# Proyecto UMAPOINTER - Plan de Usabilidad Basado en Evidencias
**Entregable N°10 – 2025-I**


## 1. Contexto de uso

**Usuario objetivo:** Pacientes con lesión medular cervical incompleta (AIS B – C7), con movilidad reducida en miembros superiores.

**Lugar de uso:**  
- Domicilio (escritorio con PC o laptop)  
- Espacios de rehabilitación o trabajo remoto

**Frecuencia de uso:**  
- Diario, sesiones de 2 a 4 horas.  

**Representación gráfica:**  
![img](https://i.imgur.com/Usyli2M.png)

*Figura: Boceto ganador del dispositivo UMAPOINTER, que muestra el uso del puntero montado sobre una vincha con control cefálico.*


## 2. Perfil del usuario

- Hombre de 28 años, ingeniero, con diagnóstico de tetraplejia incompleta por zambullida (fractura C6-C7).
- No tiene movilidad en miembros inferiores y presenta espasticidad en superiores.
- Sin capacidad de realizar movimientos finos con los dedos (ej. clic de mouse).
- Cognición conservada, motivado por retomar actividades laborales.

**Limitaciones:**
- Dolor irradiado en muñeca y antebrazo.
- Necesidad de asistencia en todas las actividades básicas.



## 3. Análisis de tareas

| Tarea                                   | Tipo    | Riesgo si falla                        |
| --------------------------------------- | ------- | -------------------------------------- |
| Colocarse la vincha con el sensor       | Básica  | Lectura errónea del movimiento         |
| Encender el sistema (ESP32)             | Básica  | No funcionamiento                      |
| Calibrar la posición inicial del cursor | Crítica | Movimientos incontrolados              |
| Mover cabeza para dirigir cursor        | Crítica | Baja precisión, frustración            |
| Ejecutar clic mediante switch externo   | Crítica | No completar acciones                  |
| Apagar sistema tras uso                 | Básica  | Consumo de batería, sobrecalentamiento |



## 4. Criterios de éxito (Requisitos de usabilidad)

| Criterio     | Indicador objetivo                                |
| ------------ | ------------------------------------------------- |
| Eficacia     | Cursor sigue el movimiento cefálico con precisión |
| Eficiencia   | Usuario completa selección en menos de 3 s        |
| Satisfacción | SUS > 70 (tras 5 usuarios simulados)              |
| Seguridad    | 0 fallos de sobrecalentamiento, 0 lesiones        |


## Componentes principales

- **ESP32-C3 Super Mini**
- **MT3608**
- **MPU6050 v2**
- **Módulo TP4056**
- **Batería LiPo recargable**
- **Cherry MX Red**
- **Arduino Pro Micro**



## Fuentes de papers usadas

- [Design and Production of Air Mouse](http://doi.org/10.26480/icie.01.2017.164.166)
- [Auxilio and Beyond – arXiv](https://arxiv.org/abs/2210.04483)
- [HeadControl+ - Springer](https://doi.org/10.1007/978-3-540-27817-7_115)



**Proyecto colaborativo por:**  
Luciana Castro, Mariano Alarcón, Adriana Bercera, Tiago Blanco, Misael Cieza

## Modelado del puntero y botones

- Vincha (Puntero)


![imgvincha](https://i.imgur.com/6fVymXj.png)
- https://cad.onshape.com/documents/6e95f2bc3fd43bf4eaa8eb82/w/3614aec3ac2cbe4a54e672ef/e/9af72efc2e59982d67a762ae
![vincha plano](https://i.imgur.com/OrVTZ84.png)
![vincha plano2](https://i.imgur.com/CGatQWP.png)
<p align="center"><strong>Plano diseñado por:</strong> Misael Andre Cieza Armas</p>

---

- Botón

![Boton](https://i.imgur.com/3O8Ss07.png)
- https://cad.onshape.com/documents/6b1e5148af9bedb4443218e9
![botonplano](https://i.imgur.com/9COT0kW.png)

- Caja base

![caja base](https://i.imgur.com/JAJDoJz.png)
- https://cad.onshape.com/documents/5e4b6f31c7cbd064d409a08c/w/6ac560c74afc353f738ac48a/e/57d5ee9f7d44679d245a2485
![cajabaseplano](https://i.imgur.com/9vl0dFD.png)

- Tapa botones
  
![tapa botones](https://i.imgur.com/2IuzuuJ.png)
- https://cad.onshape.com/documents/fd4cc8a1a3192d199dcc23fb 
![tapabotonesplano](https://i.imgur.com/wilTyQD.png)

- Tapa base

![tapa componentes](https://i.imgur.com/AMUz6oY.png)
- https://cad.onshape.com/documents/8a8d95f6aac5fabfae5a095a
![tapacomponentesplano](https://i.imgur.com/2f1Y9L8.png)
<p align="center"><strong>Planos diseñados por:</strong> Tiago Yeray Blanco Malpartida</p>
