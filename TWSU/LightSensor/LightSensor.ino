int led = 11;
int sensor = 0;
int input = 0;
int value = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  input = analogRead(sensor);
  value = map(input, 0, 1023, 0, 255);
  analogWrite(led, value);
}
