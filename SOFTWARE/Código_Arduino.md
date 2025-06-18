  #include <Mouse.h>

const int btnLeft  = 2;   // pin del botón izquierdo
const int btnRight = 3;   // pin del botón derecho

int lastL, lastR;

void setup() {
  Mouse.begin();
  pinMode(btnLeft,  INPUT_PULLUP);
  pinMode(btnRight, INPUT_PULLUP);
  lastL = digitalRead(btnLeft);
  lastR = digitalRead(btnRight);
}

void loop() {
  // Clic izquierdo
  int curL = digitalRead(btnLeft);
  if (lastL == HIGH && curL == LOW) {
    Mouse.click(MOUSE_LEFT);
    delay(100);
  }
  lastL = curL;

  // Clic derecho
  int curR = digitalRead(btnRight);
  if (lastR == HIGH && curR == LOW) {
    Mouse.click(MOUSE_RIGHT);
    delay(100);
  }
  lastR = curR;
