# Proyecto Asíncrono: Taller de Conectividad en el Borde – Grupo 1

---

## Integrantes  
- Luciana del Rosario Castro Camavilca  
- Mariano Alarcon Tirado  
- Adriana Roxana Bercera Garcia  
- Tiago Yeray Blanco Malpartida  
- Misael Andre Cieza Armas   

---

## 🎯 Objetivos

Aprender a usar el ESP32 junto con MIT App Inventor para conectar un sensor biomédico, enviar sus datos por Wi-Fi o Bluetooth, y mostrarlos en una app en tiempo real. Con el fin de reforzar conocimientos básicos de electrónica y desarrollo de aplicaciones móviles aplicadas a la biomedicina.

---

## 📸 Imágenes del taller

![InventorMIT1](https://i.imgur.com/TwmfkPd.jpeg)  
![InventorMIT2](https://i.imgur.com/zaQur15.jpeg)  
![InventorMIT3](https://i.imgur.com/IaW1fpb.jpeg)  
![InventorMIT4](https://i.imgur.com/8zmRA5o.jpeg)  
![InventorMIT5](https://i.imgur.com/ZlkWhJT.jpeg)  
![Actividad en grupo](https://i.imgur.com/d3JE33O.jpeg)

---

## 🛠️ Herramientas utilizadas

- ESP32 (microcontrolador)  
- MIT App Inventor  
- Arduino IDE  
- Sensor biomédico (pulso, flexión o temperatura)  
- Comunicación Wi-Fi / BLE  

---

## 💾 Código fuente (ESP32)

```cpp
#include <WiFiManager.h>             // Permite conectar el ESP automáticamente a una red Wi-Fi
#include <WebServer.h>               // Permite crear servidor web en ESP para manejar solicitudes HTTP

const int FLEX_PIN = A0;             // Define el pin analógico donde se conectará el sensor flex GPIO36 (ADC1_CH0)
WebServer server(80);                // Crea un servidor web

void handleADC() {
  int raw = analogRead(FLEX_PIN);          // Lee valor analógico del sensor del 0 al 4095
  int mv  = map(raw, 0, 4095, 0, 3300);     // Convierte dicho valor de 0 a 3300 milivoltios
  int angle = map(mv, 2500, 3100, 0, 90);   // Ajusta puntos recto / doblado

  // Enviar ambos valores como texto plano a la web del usuario, por ejemplo "mv,angle"
  server.send(200, "text/plain", String(mv) + "," + String(angle));
}

void setup() {
  Serial.begin(115200);                                // Inicia monitor serial 
  WiFiManager().autoConnect("FlexAP", "12345678");     // Intenta conectarse al Wi-Fi guardado
  server.on("/readADC", handleADC);                    // Cuando alguien ingrese al /readADC, se ejecutará handleADC()
  server.begin();                                      // Inicia servidor web
}

void loop() {
  server.handleClient();    // Atiende a solicitudes del usuario
}
```

---

## 📽️ Video del taller

[![Ver video en YouTube](https://img.youtube.com/vi/UlYp3csdt6A/hqdefault.jpg)](https://youtu.be/UlYp3csdt6A)

