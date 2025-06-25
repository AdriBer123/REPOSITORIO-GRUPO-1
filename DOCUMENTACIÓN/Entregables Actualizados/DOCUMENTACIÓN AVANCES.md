# DOCUMENTACIÓN AVANCES FINALES DEL PROTOTIPADO:

---

## ONSHAPE:

### - VINCHA [1]

![imagen1](https://i.imgur.com/4rjOIju.png)


![imagen1B](https://i.imgur.com/q0vXmzq.png)


### - CAJA DE ENSAMBLAJE [2]

![imagen2](https://i.imgur.com/LBIBFUU.png)


### - BOTÓN [3]
  
![imagen3](https://i.imgur.com/x6AWo2q.png)


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

 
