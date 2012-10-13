#include <Servo.h>

Servo servo;
int poten = 0;
int input = 0;

void setup() {
  servo.attach(9);
}

void loop() {
  poten = analogRead(0);
  // http://arduino.cc/en/Reference/Map
  // Servo goes from 0 and 180
  input = map(poten, 0, 1023, 0, 180);
  servo.write(input / 2);
}
