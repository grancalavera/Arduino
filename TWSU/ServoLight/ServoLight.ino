/*
 ServoLight
*/

#include <Servo.h>

Servo servo;
int light = 0;
int input = 0;

void setup() {
  servo.attach(9);
}

void loop() {
  light = analogRead(0);
  input = map(light, 0, 1023, 0, 180);
  servo.write(input);
}
