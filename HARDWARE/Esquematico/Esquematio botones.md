![img](https://i.imgur.com/bavVSOf.png)

# Documentación de Esquematico de Botones

---

## 1. Diseño Inicial

1. **Arduino Pro Mini** (ATmega328P)  
2. **Módulo Bluetooth HC-05** para la comunicación inalámbrica  
3. **Dos pulsadores** (switches) para clic izquierdo y clic derecho  

---

## 2. Separación de Funciones

- Se observó que el **puntero de cabeza** (bincha con MPU6050 y ESP32) y la **botonera** podían operar de forma **independiente**.
- **HC-05** quedaba sobredimensionado para la botonera, por lo que se **eliminó** del diseño.

---

## 3. Procesamiento HID en Microcontrolador

- El **Arduino Pro Mini** **no** dispone de un **chip USB-HID** que emule un ratón directamente.
- Se **reemplazó** por **Arduino Pro Micro** (ATmega32U4), que incorpora el controlador USB nativo y es compatible con la **librería Mouse** de Arduino.

---

## 4. Conexión de Pulsadores

- Se emplearon **pines digitales** del Pro Micro:
  - **Pin 4** → Pulsador **Clic Izquierdo**  
  - **Pin 5** → Pulsador **Clic Derecho**  
- Ambos pulsadores hacen **masa a GND** cuando se accionan.
- **No** se usa el pin VCC externo, ya que el Pro Micro dispone de su propio **regulador interno** de 5 V / 3.3 V.

---

## 5. Librería Mouse

- La **librería Mouse** de Arduino permite que el Pro Micro sea reconocido por el sistema operativo como un **dispositivo HID de ratón**.
- Ventajas:
  - **Plug & play**: Windows/macOS/Linux detectan los clics sin controladores adicionales.  
  - **API sencilla**: `Mouse.click()`, `Mouse.move()`, etc.

---

## 6. Resumen de Beneficios

| Aspecto                   | Antes (Pro Mini + HC-05)        | Ahora (Pro Micro)                        |
|---------------------------|---------------------------------|------------------------------------------|
| Soporte USB-HID           | No disponible                   | Nativo (ATmega32U4)                      |
| Comunicación inalámbrica  | HC-05 (Bluetooth clásico)       | BLE (ESP32 en el módulo de cabeza)       |
| Complejidad de hardware   | Módulo extra (HC-05)            | Reducida (solo Pro Micro + switches)     |
| Detección en PC           | Requiere adaptador HID externo  | Directa como ratón                       |

Con este cambio, la botonera es más **ligera**, **fiable** y se integra de forma **nativa** con el ordenador como un ratón estándar.  
