int red     = 11;
int yellow  = 12;
int green   = 13;

int redTime     = 4000;
int yellowTime  = 1500;
int greenTime   = 3000;
int greenBlink  = 150;
int blinks      = 8;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH);
  delay(redTime);

  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(yellowTime);

  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(greenTime);

  digitalWrite(green, LOW);

  for (int i = 0; i < blinks; i++) {
    digitalWrite(green, HIGH);
    delay(greenBlink);
    digitalWrite(green, LOW);
    delay(greenBlink);
  }
}
