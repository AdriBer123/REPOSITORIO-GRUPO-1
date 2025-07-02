##
![img](https://i.imgur.com/TupWxFd.png)

# Documentación del Diseño Esquemático y Circuitos Electrónicos

Este repositorio describe el diseño esquemático de un sistema de puntero de cabeza basado en ESP32 Mini y MPU6050, dividido en dos bloques principales:

1. **Bloque de Alimentación**  
2. **Bloque de Sensor y Microcontrolador**

---

## 1. Descripción General

- **Bloque de Alimentación**: Genera y regula los voltajes necesarios (carga, batería y regulación).  
- **Bloque de Sensor + Microcontrolador**: ESP32 Mini + MPU6050 para captura de movimiento y emulación HID vía BLE.

---

## 2. Bloque de Alimentación

### 2.1 Módulo de carga
- Gestión de carga segura de batería LiPo (3.7 V).

### 2.2 Batería de litio
- Batería recargable LiPo 3.7 V.

### 2.3 Regulador de voltaje
- Convierte 3.7 V → **5 V** estabilizados.
- Alimenta el ESP32 Mini (Vin) y, a través de éste, el MPU6050.

---

## 3. Bloque de Sensor y Microcontrolador

### 3.1 ESP32 Mini
- Microcontrolador principal.
- Alimentación: **5 V** en Vin, despierta un regulador interno a 3.3 V.
- Funciones:
  - Leer datos I²C del MPU6050.
  - Emular dispositivo HID (mouse) vía BLE.

### 3.2 MPU6050
- Sensor 6 ejes (acelerómetro + giroscopio).
- Alimentación: **3.3 V** (pin regulado interno del ESP32).
- Comunicación: **I²C** (SDA / SCL).

### 3.3 Conexiones de Tierra (GND)
- El regulador de 5 V solo ofrece una pata de GND.
- Se crea una **derivación en “Y”** desde la salida GND del regulador:
  - Una rama → GND del ESP32 Mini.
  - Otra rama → GND del MPU6050.

---

## 4. Comunicación

| Señal | Origen                | Destino        |
|:-----:|:----------------------|:---------------|
| SDA   | Pin SDA del ESP32 Mini| Pin SDA MPU6050|
| SCL   | Pin SCL del ESP32 Mini| Pin SCL MPU6050|

El ESP32 interroga periódicamente al MPU6050 para obtener datos de aceleración y giro.

---

## 5. Consideraciones y Soluciones

- **Única pata de GND**  
  - Solución: Cable en “Y” para alimentar GND de ESP32 y MPU6050.  
- **Regulación de voltaje**  
  - Batería 3.7 V → Regulador → 5 V → ESP32 → 3.3 V interno → MPU6050.  
- **Estabilidad**  
  - Garantiza niveles de tensión apropiados para evitar sobrevoltajes y ruido.

---
