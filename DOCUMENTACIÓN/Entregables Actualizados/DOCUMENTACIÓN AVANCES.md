# DOCUMENTACIÓN AVANCES FINALES DEL PROTOTIPADO:

---

## MODELADO 3D PROCEDIMIENTO 

### - VINCHA PUNTERO

![imgvincha](https://i.imgur.com/6fVymXj.png)


![imagen1B](https://i.imgur.com/Rl9kNPA.png)

### - VINCHA PUNTERO (MODELO ANTERIOR)

![imagen1](https://i.imgur.com/EuKSWCx.png)

- La vincha fue concebida con una forma de arco parecida a la vincha de uso corriente, dividiéndose en dos partes principales:

- **Tapa frontal**
- **Tapa posterior**

La **tapa posterior** fue diseñada con el propósito de alojar los componentes electrónicos. Para asegurar su estabilidad, se incorporó una **estructura recta interna**, que cumple la función de fijar los elementos electrónicos en una única posición en la parte superior, evitando desplazamientos durante el uso.

- Además, se diseñó un sistema de **ensamble ** entre ambas tapas. Este ensamble permite que, tras ser impresas, las piezas puedan **acoplarse fácilmente mediante un mecanismo de enganche**, posibilitando la apertura y el cierre de la vincha de forma práctica, facilitando tanto el montaje de los componentes como el mantenimiento del dispositivo.

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

- Adicionalmente, como parte del desarrollo, se diseñó también una botonera de dos botones que debía integrarse a otro sistema complementario. Esta parte del diseño presentó sus propios retos técnicos. Inicialmente, los orificios destinados a los switches tipo Redragon no encajaban correctamente, lo cual obligó a realizar varias iteraciones para ajustar su diámetro y profundidad. Además, se presentaron dificultades al momento de integrar el Arduino pro micro dentro de la carcasa, ya que su tamaño y disposición de pines exigían una redistribución del espacio interno. Otro detalle complejo fue el manejo de la entrada microUSB: su orientación y accesibilidad fueron problemáticas dentro del modelo original, por lo que se requirió modificar el diseño externo para permitir una conexión directa sin forzar el conector. Estas modificaciones fueron necesarias para asegurar la funcionalidad y durabilidad del conjunto, manteniendo siempre la simplicidad de uso como prioridad del proyecto.

### - ERRORES IMPRESION 3D

A continuación, se detallan los principales problemas encontrados y las soluciones implementadas:

### 1. Error en la impresión del botón

- En un primer intento, el botón fue orientado de forma invertida en la cama de impresión. Esta orientación provocó una mala adhesión de las capas iniciales, lo que resultó en una pieza incompleta y con pérdida de material, impidiendo que se formara correctamente el volumen del botón.

- **Solución aplicada:**  
  Se reorientó el botón en su posición correcta y se añadieron soportes internos en la configuración de impresión, especialmente alrededor del área de encaje donde iba el switch. Esto mejoró significativamente la estabilidad durante la impresión y permitió obtener una pieza completamente funcional.

### 2. Problema con la vincha del modelado

- Al imprimir la estructura de la vincha, se utilizó una configuración de soporte inadecuada. El soporte aplicado no era suficientemente resistente para sostener el peso y volumen de la pieza. Como consecuencia, la impresión presentó deformaciones, pérdida de detalle y ciertas secciones del material se doblaron, impidiendo un correcto encaje entre componentes.

- **Solución aplicada:**  
  Se rediseñó el sistema de soportes, añadiendo refuerzos adicionales, especialmente en las zonas con huecos para los encajes. Además, se ajustaron los parámetros de impresión, aumentando el tiempo y la densidad de soporte para asegurar una mejor definición estructural y un acabado fiel al modelado original.

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

 
