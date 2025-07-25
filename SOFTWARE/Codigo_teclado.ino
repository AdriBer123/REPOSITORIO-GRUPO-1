/*
	Capitulo 57 de Arduino desde cero en Español.
	Emulacion de mouse (HID) con Pro Micro para boton izquierdo y derecho
	
	https://www.youtube.com/c/BitwiseAr
	Autor: bitwiseAr  

*/

#include "Mouse.h"	// incluye libreria Mouse

#define IZQUIERDO 4	// constante para identificar pulsador izquierdo en pin 4
#define DERECHO 5	// constante para identificar pulsador derecho en pin 5

#define DEMORA 100	// constante para demora entre lecturas de pulsadores

void setup() {
  pinMode(IZQUIERDO, INPUT_PULLUP);	// pin 4 como entrada con resistencia de pull-up
  pinMode(DERECHO, INPUT_PULLUP);	// pin 5 como entrada con resistencia de pull-up
  Mouse.begin();			// inicio de emulacion de mouse
}

void loop() {
  if (digitalRead(IZQUIERDO) == LOW) {	// si se ha presionado el pulsador izquierdo
    Mouse.press(MOUSE_LEFT);		// funcion para presionar boton izquierdo del mouse
    delay(DEMORA);			// demora de 100 mseg.
    Mouse.release(MOUSE_LEFT);		// funcion para dejar de presionar boton izquierdo
  }
  
  if (digitalRead(DERECHO) == LOW) {	// si se ha presionado el pulsador izquierdo
    Mouse.press(MOUSE_RIGHT);		// funcion para presionar boton derecho del mouse
    delay(DEMORA);			// demora de 100 mseg.
    Mouse.release(MOUSE_RIGHT);		// funcion para dejar de presionar boton derecho
  }
  
  delay(DEMORA);			// demora de 100 mseg.
}