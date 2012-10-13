/*
  Foo bar man
*/
const int BUTTON_PIN  = 2;
const int LED_PIN     = 13;

int buttonState       = LOW;
int onTime            = 5000;
int onAt              = 0;

boolean isPushing     = false;
boolean isOn          = false;
boolean isDimming     = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop(){
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH && !isPushing) {
    isPushing = true;
    if (!isOn) turnOn();
    else if (isOn) turnOff();
  }

  if (buttonState == LOW && isPushing) {
    isPushing = false;
    onAt = millis();
  }

  if (isOn && !isPushing && isTimeUp()) {
    turnOff();
  }
}

void turnOn() {
  isOn = true;
  analogWrite(LED_PIN, 255);
}

void turnOff() {
  isOn = false;
  analogWrite(LED_PIN, 0);
}

boolean isTimeUp() {
  return (millis() - onAt) >= onTime;
}

