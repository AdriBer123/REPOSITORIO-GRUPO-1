#include <BleMouse.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define SDA_PIN     4   // GPIO4 (SDA)
#define SCL_PIN     3   // GPIO3 (SCL)
#define SENSITIVITY 10

BleMouse bleMouse;
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("FUNDAMENTOS DE BIODISEÑO");

  bleMouse.begin();               // HID BLE mouse por defecto

  // I2C en los pines correctos
  Wire.begin(SDA_PIN, SCL_PIN);
  if (!mpu.begin()) {
    Serial.println("¡No encuentra el MPU6050!");
    while (1) delay(10);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
}

void loop() {
  if (bleMouse.isConnected()) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    int dx = g.gyro.z * -SENSITIVITY;
    int dy = g.gyro.x * -SENSITIVITY;
    if (dx || dy) {
      bleMouse.move(dx, dy);
    }
  }
  delay(15);
}
