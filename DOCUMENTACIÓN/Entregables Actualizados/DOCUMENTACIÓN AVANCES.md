# DOCUMENTACIÓN AVANCES FINALES DEL PROTOTIPADO:

---

## MODELADO 3D PROCEDIMIENTO 

### - VINCHA PUNTERO

![imgvincha](https://i.imgur.com/6fVymXj.png)


![imagen1B](https://i.imgur.com/Rl9kNPA.png)

### - VINCHA PUNTERO (MODELO ANTERIOR)

![imagen1](https://i.imgur.com/EuKSWCx.png)

- Durante el desarrollo del modelo de vincha, se presentó una serie de situaciones que requirieron ajustes progresivos tanto en el diseño como en el enfoque general del proyecto. Inicialmente, el modelo contaba con una estructura cuya medida interna era de aproximadamente 15 centímetros, lo cual resultó ser insuficiente para adaptarse ergonómicamente a una cabeza humana promedio. Esto fue identificado durante una verificación previa a la impresión, lo cual permitió tomar acciones correctivas a tiempo. Se procedió a escalar la parte trasera del diseño con un factor de 1.333 en el eje X, logrando así alcanzar una medida interna de 20 centímetros. Sin embargo, esto generó un nuevo problema: la parte delantera de la vincha no fue escalada en conjunto, provocando una desalineación entre ambas piezas.
- Este desajuste obligó a revisar manualmente las proporciones de cada parte y a realizar una comparación directa para identificar los factores exactos de escalado aplicados. A partir de ello, se corrigió también la parte frontal para que ambos elementos encajaran correctamente, sin comprometer la continuidad del diseño ni la funcionalidad del cierre.
- Posteriormente, se detectó que el compartimiento central destinado a alojar los componentes se había modificado de forma no deseada tras el escalado. En lugar de ampliarse proporcionalmente, algunas áreas se volvieron menos útiles para alojar las piezas y se perdía espacio valioso. Para solucionar esto, se rediseñó el volumen interno mediante operaciones de corte, recuperando el espacio necesario para integrar los módulos de forma eficiente.

- También se identificaron interferencias en las entradas para los conectores, debido a que se consideró inicialmente un montaje por soldadura directa, pero en realidad se utilizaron conectores tipo galleta. Esto requería mayor holgura en los accesos, por lo que se realizaron modificaciones puntuales en esas zonas, ampliando los huecos de paso para permitir el ingreso cómodo de cables sin forzar el material ni obstaculizar la conexión.

- Finalmente, se incorporó un nuevo requerimiento: habilitar espacio para un switch físico de encendido y apagado. Esto implicó generar un corte adicional en la parte superior del modelo, respetando tanto la estética como el espesor estructural del diseño para evitar fragilidad.



### - BOTONES 
  
![imagen3](https://i.imgur.com/OyxSUsG.png)
![imagenbase](https://i.imgur.com/1U12a0k.png)

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

 
