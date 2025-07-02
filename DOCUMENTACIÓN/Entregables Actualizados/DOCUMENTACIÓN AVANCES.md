# DOCUMENTACIÓN AVANCES FINALES DEL PROTOTIPADO:

---

## MODELADO 3D PROCEDIMIENTO 

### - VINCHA PUNTERO

![imgvincha](https://i.imgur.com/6fVymXj.png)


![imagen1B](https://i.imgur.com/Rl9kNPA.png)

### - VINCHA PUNTERO (MODELO ANTERIOR)

![imagen1](https://i.imgur.com/EuKSWCx.png)

### - BOTONES 
  
![imagen3](https://i.imgur.com/OyxSUsG.png)
![imagenbase](https://i.imgur.com/eRMdegs.png)

### - BOTONES (MODELO ANTERIOR)

![imagen2](https://i.imgur.com/OBkpStt.png)

---

## CIRCUITOS CÓDIGO CLICKS:

```cpp
#include <Mouse.h> 
#include <SoftwareSerial.h> 

SoftwareSerial btSerial(10, 11); // HC-05 conectado a los pines 10 y 11 (ajusta si es necesario) 

const int leftButtonPin = 4; 
const int rightButtonPin = 5; 

void setup() { 
  pinMode(leftButtonPin, INPUT);   
  pinMode(rightButtonPin, INPUT); 

  btSerial.begin(9600); // Comunicación con el HC-05   
  Mouse.begin();        // Inicia la simulación del mouse 
} 

void loop() { 
  // Leer los datos del puntero (movimiento de la cabeza) 
  if (btSerial.available()) { 
    String data = btSerial.readString(); 

    int commaIndex1 = data.indexOf(','); 
    int commaIndex2 = data.indexOf(',', commaIndex1 + 1); 

    int gx = data.substring(0, commaIndex1).toInt(); 
    int gy = data.substring(commaIndex1 + 1, commaIndex2).toInt(); 
    int gz = data.substring(commaIndex2 + 1).to
```cpp

 
