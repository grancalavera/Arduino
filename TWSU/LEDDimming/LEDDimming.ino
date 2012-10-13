/*
  Dimming leds with a potenciometer
*/
int red = 11;
int green = 10;

// sensors give values from 0 to 1023
int dimmFactor = 0;

void setup() {
  pinMode(red, OUTPUT);
}

void loop() {
  dimmFactor = analogRead(0);
  // from 0 to 255
  analogWrite(red, dimmFactor / 4);
  analogWrite(green, 255 - (dimmFactor / 4));
}

