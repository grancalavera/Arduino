#define LED 13

int delayTime = 1000;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(delayTime);
  
  digitalWrite(LED, LOW);
  delay(delayTime);
}