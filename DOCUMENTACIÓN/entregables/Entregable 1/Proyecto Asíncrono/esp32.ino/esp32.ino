#include <WiFiManager.h>             // Permite conectar el ESP automaticamente a una red Wi fi
#include <WebServer.h>               // Permite crear servidor web en ESP para manejrar solicitudes HTTP

const int FLEX_PIN = A0;             // Define el pin analogico donde se conectará el sensor flex GPIO36 (ADC1_CH0)
WebServer server(80);                //Crea un servidor web

void handleADC(){
  int raw = analogRead(FLEX_PIN);          // lee valor analogico del sensor del 0 al 4095
  int mv  = map(raw, 0, 4095, 0, 3300);    // convierte dicho valor de 0 a 3300 milivoleteos
  int angle = map(mv, 2500, 3100, 0, 90);  // ajusta puntos recto / doblado

  // Enviar ambos valores como texto plano a la web del usuario, por ejemplo "mv,angle"
  server.send(200, "text/plain", String(mv) + "," + String(angle));
}

void setup(){
  Serial.begin(115200);                                //Inicia monitor serial 
  WiFiManager().autoConnect("FlexAP", "12345678");     //intenta conectarse al Wi Fi guardado
  server.on("/readADC", handleADC);                    //Cuando alguien ingrese al readADC, se ejecutará handleADC()
  server.begin();                                      //inicia servidor web
}

void loop(){
  server.handleClient();    //atiende a solicitudes del usuario
}
