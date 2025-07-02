# Entregable 9: Diseño esquemático y simulación electrónica del prototipo

---

## Papers:

### - Design and Production of Air Mouse [1]

**Tipo de producto:**  
Dispositivo air mouse inalámbrico para controlar el cursor del computador en un espacio tridimensional, utilizando sensores MPU6050 (acelerómetro y giroscopio) y tecnología de transmisión inalámbrica NRF24L01.

**Tipo de usuarios:**  
- Personas que requieren control de la computadora sin usar el ratón tradicional.  
- Usuarios de entornos educativos, hogares, presentaciones y conferencias.  
- Personas que desean una interfaz de interacción más cómoda y sin manos.

**Métodos de evaluación:**  
- Evaluación de rendimiento: sensibilidad y precisión del movimiento del cursor.  
- Pruebas de usabilidad con joystick y Mindwave+MPU6050.  
- Monitoreo de energía: consumo de 0.18W.

**Criterios de éxito:**  
- **Eficacia:** Movimiento preciso en 3D, sin errores importantes.  
- **Eficiencia:** Buen control del cursor, aunque el Mindwave+MPU6050 fue más lento que el joystick.  
- **Satisfacción:** Diseño intuitivo; control con la cabeza fue un reto en curvas.  
- **Seguridad:** Sin errores graves; el control con Mindwave es sensible a la concentración del usuario.

**Evidencia recogida:**  
- Datos de pruebas con cinco participantes.  
- Medición de consumo energético.  
- Comentarios positivos de los usuarios.

**Lecciones aplicables a mi proyecto:**  
- Integración de sensores como MPU6050 y Mindwave junto a algoritmos (ej. Kalman) mejora la precisión.  
- Considerar sensibilidad ambiental en sistemas de control físico remoto.

---

### - Auxilio and Beyond [2]

**Tipo de producto:**  
Mouse asistivo montado en la cabeza, con sensores de movimiento e infrarrojos para detectar movimientos y contracciones musculares faciales.

**Tipo de usuarios:**  
- Personas con discapacidades en extremidades superiores.  
- Participaron también personas sin discapacidades para evaluación comparativa.

**Métodos de evaluación:**  
- Comparación con mouse comercial (Smyle Mouse).  
- Tareas de apuntado y clic en juego interactivo.  
- Métricas de rendimiento, SUS y entrevistas.

**Criterios de éxito:**  
- Precisión en tareas, eficiencia del trayecto del cursor, tasa de error y escala SUS.

**Evidencia recogida:**  
- Datos cuantitativos, puntuaciones SUS y entrevistas.

**Lecciones aplicables a mi proyecto:**  
- Uso combinado de sensores de movimiento e infrarrojos mejora el control.  
- Pruebas comparativas y feedback cualitativo enriquecen el diseño.

---

### - HeadControl+: A Multi-modal Input Device [3]

**Tipo de producto:**  
Prototipo multimodal basado en láser, controlado por movimientos de cabeza, emulando funciones de mouse y teclado.

**Tipo de usuarios:**  
- Personas con discapacidades motoras.

**Métodos de evaluación:**  
- Pruebas funcionales con hardware comercial, validando múltiples modos de entrada.

**Criterios de éxito:**  
- Emulación efectiva de mouse y teclado.  
- Adaptabilidad a diversos contextos.

**Evidencia recogida:**  
- Resultados de pruebas en diferentes escenarios.

**Lecciones aplicables a mi proyecto:**  
- Usar hardware comercial facilita replicabilidad y reduce costos.  
- Incluir múltiples modos de entrada mejora la versatilidad.  
- Tecnologías como el control por láser son alternativas válidas.

---

## Capturas y links de los componentes (Onshape)

**ESP32-C3 Super Mini**
[imgesp32](https://i.imgur.com/3qepDal.png)
- https://cad.onshape.com/documents/549eed835500a0cd41b9e5b0/w/a94682eda86d8d6b579f9ad9/e/162e2235962722d09a943fca

**Batería LiPo recargable**
[imgbateria](https://i.imgur.com/x3SVfjF.png)
- https://cad.onshape.com/documents/ed993d2e9ef4bdde87268878/w/5b1a02649482a25a209dda19/e/dcb735930d4d798676c14d0b

**Arduino Pro Micro**
[imgarduinopromicro](https://imgur.com/KA8ByLt)
- https://cad.onshape.com/documents/f0f6637fafaa73e0a5398a32/w/b92d714e98a0265364e88df2/e/fd0e825461639b419d45d633
  
**MT3608**  
![imagen5](https://i.imgur.com/WAEgJT8.png)
- https://cad.onshape.com/documents/e02452d69f3cf72f6de63b40/w/901697ce36c91d37e53e1447/e/39c8df694a27cdc978f8670c 

**MPU6050 v2**  
![imagen7](https://i.imgur.com/ExqJleb.jpeg)
- https://cad.onshape.com/documents/880c3f45901fde9c32cb2191/w/2927013b7f5543a1986ab1db/e/d070e595353c137b1bdb37ae

**Cherry MX Red**  
![imagen8](https://i.imgur.com/Ilv8QIn.jpeg)



**TP4056**  
![imagen10](https://i.imgur.com/o3bE0F4.jpeg)
- https://cad.onshape.com/documents/e26b06da237180d41eb9163e/w/cca49bde8a7ac7a1390ef138/e/2a9d502c525a05d0ba7f979a

---

## Referencias:

1. [Design and Production of Air Mouse](http://doi.org/10.26480/icie.01.2017.164.166)  

2. [Auxilio and Beyond](https://arxiv.org/abs/2210.04483)  

3. [HeadControl+](https://doi.org/10.1007/978-3-540-27817-7_115)  


