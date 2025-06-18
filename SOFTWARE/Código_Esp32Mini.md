#include <BleMouse.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// --- Ajusta estos valores según tu placa
#define SDA_PIN 21
#define SCL_PIN 22
#define SENSITIVITY 10

BleMouse bleMouse;          // crea el periférico BLE HID
Adafruit_MPU6050 mpu;       // objeto MPU6050

void setup() {
  Serial.begin(115200);

  // Inicializa BLE-Mouse
  bleMouse.begin();

  // I2C para el MPU6050
  Wire.begin(SDA_PIN, SCL_PIN);
  if (!mpu.begin()) {
    Serial.println("¡No encuentra el MPU6050!");
    while (1) delay(10);
  }
  // Opcional: ajustes de rango
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
}

void loop() {
  // Si estamos conectados por BLE:
  if (bleMouse.isConnected()) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // g.gyro.x/y/z en rad/s; mapea a un delta de pixeles
    int dx = g.gyro.z * -SENSITIVITY;
    int dy = g.gyro.x * -SENSITIVITY;

    // Mueve el mouse
    if (dx || dy) {
      bleMouse.move(dx, dy);
    }
  }
  delay(15);  // control de tasa de envío
