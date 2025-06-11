#include <Wire.h> 

#include <MPU6050.h> #include <SoftwareSerial.h> 

MPU6050 mpu; 

SoftwareSerial btSerial(10, 11); // HC-05 conectado a los pines 10 y 11 (ajusta si es necesario) 

void setup() { 

`  `Serial.begin(115200); 

`  `btSerial.begin(9600); // Comunicación con el HC-05 a 9600 bps 

`  `Wire.begin(); 

`  `mpu.initialize();  // Inicializamos el MPU6050 

`  `if (!mpu.testConnection()) { 

`    `Serial.println("Error de conexión con el MPU6050");     while (1); 

`  `} 

} 

void loop() { 

`  `// Leer los valores del giroscopio 

`  `int16\_t ax, ay, az, gx, gy, gz; 

`  `mpu.getAcceleration(&ax, &ay, &az);   mpu.getRotation(&gx, &gy, &gz); 

`  `// Enviar los valores al Arduino Pro Micro   btSerial.print(gx); 

`  `btSerial.print(","); 

`  `btSerial.print(gy); 

`  `btSerial.print(","); 

`  `btSerial.println(gz); 

`  `delay(100);  // Enviar los datos cada 100ms (ajustable) } 
