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

**ESP32 Dev [4]**  
![imagen4](https://i.imgur.com/6DFdnXe.png)


**MT3608 Converter [5]**  
![imagen5](https://i.imgur.com/8CKUwUc.jpeg)


**MPU6050 v2 [6]**  
![imagen7](https://i.imgur.com/ExqJleb.jpeg)


**Switch [7]**  
![imagen8](https://i.imgur.com/Ilv8QIn.jpeg)


**ESP32 Mini S2 [8]**  
![imagen9](https://i.imgur.com/AAXbXmY.jpeg)


**TP4056 (módulo de cargador) [9]**  
![imagen10](https://i.imgur.com/o3bE0F4.jpeg)


---

## Referencias:

1. [Design and Production of Air Mouse](http://doi.org/10.26480/icie.01.2017.164.166)  

2. [Auxilio and Beyond](https://arxiv.org/abs/2210.04483)  

3. [HeadControl+](https://doi.org/10.1007/978-3-540-27817-7_115)  

4. [ESP32 Dev (Onshape)](https://cad.onshape.com/documents/e838083a8c9c2e7f3030b74f/w/c3c0e9778ff4308d97538232/e/21aeb2076cc295a957906ed7)  

5. [MT3608 Converter](https://cad.onshape.com/documents/215613de35af92d1d58ed02c/w/eba9cc5ec25d848dca14f70c/e/abba0b0d830f44dd5bc24a27)  
 
6. [MPU6050 v2](https://cad.onshape.com/documents/dfdbd496d6de2e2e93f890d3/w/02a44f5211c629383defbb28/e/f40f0816bad3977643b926d0)  

7. [Switch](https://cad.onshape.com/documents/b7f716d591744709d5c215db/w/3686a479853cd300741ec2c0/e/7a7dda0e091fe190815debf3)  

8. [ESP32 Mini S2](https://cad.onshape.com/documents/120f7d5b94674933f9d3a4c3/w/f282ae493a0f283854dbfc86/e/4012d9beba7533c0fda757e7)  

9. [Módulo de cargador (TP4056)](https://cad.onshape.com/documents/76fdfd1366ccb230b21696d7/w/f8b207a63cda3b865bfb2de2/e/26ce4c981e1b3b7b9cd44b5a)  


