#include <Mouse.h> #include <SoftwareSerial.h> 

SoftwareSerial btSerial(10, 11); // HC-05 conectado a los pines 10 y 11 (ajusta si es necesario) 

const int leftButtonPin = 4; const int rightButtonPin = 5; 

void setup() { 

    pinMode(leftButtonPin, INPUT);   pinMode(rightButtonPin, INPUT); 

    btSerial.begin(9600); // Comunicación con el HC-05   Mouse.begin(); // Inicia la simulación del mouse 

} 

void loop() { 

    // Leer los datos del puntero (movimiento de la cabeza) 

    if (btSerial.available()) { 

    String data = btSerial.readString(); 

    int commaIndex1 = data.indexOf(','); 

    int commaIndex2 = data.indexOf(',', commaIndex1 + 1); 

int gx = data.substring(0, commaIndex1).toInt(); 

int gy = data.substring(commaIndex1 + 1, commaIndex2).toInt(); int gz = data.substring(commaIndex2 + 1).toInt(); 

    // Simula el movimiento del mouse 

      Mouse.move(gx / 100, gy / 100);  // Ajusta la escala para controlar la velocidad del cursor   } 

    // Leer los botones 

    if (digitalRead(leftButtonPin) == HIGH) {     Mouse.press(MOUSE\_LEFT); 

    } else { 

    Mouse.release(MOUSE\_LEFT); 

    } 

    if (digitalRead(rightButtonPin) == HIGH) {     Mouse.press(MOUSE\_RIGHT); 

    } else { 

      Mouse.release(MOUSE\_RIGHT); 

    } 

`  `delay(10);  // Pequeña pausa para evitar sobrecargar el procesador } 
