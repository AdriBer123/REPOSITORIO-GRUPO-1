// Demo MPU6050 + BLE-Mouse HID
#include <BleMouse.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <math.h>

// Pines I²C
#define SDA_PIN     4  // tu SDA en GPIO4
#define SCL_PIN     3  // tu SCL en GPIO3

// Sensibilidad y zonas muertas
#define SENS_H      8.0f   // pixeles/(rad/s) horizontal
#define SENS_V      6.0f   // pixeles/(rad/s) vertical
#define DEAD_H      0.03f  // rad/s umbral horizontal
#define DEAD_V      0.03f  // rad/s umbral vertical
#define SMOOTH      0.2f   // 0..1, 1 = sin suavizado
#define DT          0.015f // loop ≈ 15 ms

BleMouse         bleMouse;
Adafruit_MPU6050 mpu;

// Bias del giróscopo (offset)
float biasX = 0, biasY = 0, biasZ = 0;
// Señal suavizada
float dx_s = 0, dy_s = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  // Arranca el MPU6050
  if (!mpu.begin()) {
    Serial.println("¡Error: MPU6050 no encontrado!");
    while (1) delay(10);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

  // Calibración de bias (2 s en reposo)
  Serial.println("Calibrando giróscopo: mantén el módulo estable...");
  unsigned long t0 = millis();
  long sumX = 0, sumY = 0, sumZ = 0;
  int cnt = 0;
  while (millis() - t0 < 2000) {
    sensors_event_t a, g, tmp;
    mpu.getEvent(&a, &g, &tmp);
    sumX += g.gyro.x;
    sumY += g.gyro.y;
    sumZ += g.gyro.z;
    cnt++;
    delay(10);
  }
  biasX = sumX / float(cnt);
  biasY = sumY / float(cnt);
  biasZ = sumZ / float(cnt);
  Serial.printf("Bias calibrado X=%.5f Y=%.5f Z=%.5f\n", biasX, biasY, biasZ);

  // Inicia el mouse BLE
  bleMouse.begin();
  Serial.println("Empareja ahora 'ESP32-BLE-Mouse' en tu PC");
  delay(500);
}

void loop() {
  // Si no hay conexión BLE, salimos rápido
  if (!bleMouse.isConnected()) {
    delay(50);
    return;
  }

  // Lectura del sensor
  sensors_event_t a, g, tmp;
  mpu.getEvent(&a, &g, &tmp);

  // Imprime valores por Serial
  Serial.print("Acc X: "); Serial.print(a.acceleration.x, 2);
  Serial.print(" Y: ");      Serial.print(a.acceleration.y, 2);
  Serial.print(" Z: ");      Serial.print(a.acceleration.z, 2);
  Serial.println(" m/s²");

  Serial.print("Gyro X: ");  Serial.print(g.gyro.x, 2);
  Serial.print(" Y: ");      Serial.print(g.gyro.y, 2);
  Serial.print(" Z: ");      Serial.print(g.gyro.z, 2);
  Serial.println(" rad/s");

  Serial.print("Temp: ");    Serial.print(tmp.temperature, 1);
  Serial.println(" °C");
  Serial.println();

  // --- Movimiento de cursor ---
  // 1) Quita drift
  float rateX = g.gyro.x - biasX; // cabeceo → dy
  float rateY = g.gyro.y - biasY; // giro → dx

  // 2) Dead-zone
  if (fabs(rateX) < DEAD_V) rateX = 0;
  if (fabs(rateY) < DEAD_H) rateY = 0;

  // 3) Si está quieto, resetea suavizado y no muevas
  if (rateX == 0 && rateY == 0) {
    dx_s = dy_s = 0;
    delay((int)(DT*1000));
    return;
  }

  // 4) Mapea a píxeles
  float dx =  rateY * SENS_H;
  float dy = -rateX * SENS_V; // invierte para que inclinar adelante suba cursor

  // 5) Suavizado exponencial
  dx_s = SMOOTH*dx + (1 - SMOOTH)*dx_s;
  dy_s = SMOOTH*dy + (1 - SMOOTH)*dy_s;

  int mx = int(round(dx_s));
  int my = int(round(dy_s));

  // 6) Mueve el cursor
  bleMouse.move(mx, my);

  delay((int)(DT*1000));
}
