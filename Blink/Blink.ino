/*
  First sketch: blinking LED every 2 seconds
*/
int red   = 11;
int green = 12;
int times = 7;
int fast = 80;
int slow = fast * 10;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

// 16 MHz
void loop() {
  for (int i = 0; i < times; i ++) {
    greenOn();
    delay(fast);
    redOn();
    delay(fast);
  }
  allOff();
  delay(slow);
}

void greenOn() {
  on(green);
  off(red);
}

void redOn() {
  on(red);
  off(green);
}

void allOff() {
  off(green);
  off(red);
}
void on(int led) {
  digitalWrite(led, HIGH);
}

void off(int led) {
  digitalWrite(led, LOW);
}
