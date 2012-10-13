#include <Bounce.h>

/*
  Foo bar man
*/
#include <Bounce.h>

const int BUTTON_PIN  = 2;
const int LED_PIN     = 13;

Bounce button         = Bounce(BUTTON_PIN, 100);
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
  button.update();
  buttonState = button.read();
}

void loop(){
  if (button.update()) {
    buttonState = button.read();
    if (buttonState == HIGH) {
      if (!isOn) turnOn();
      else turnOff();
    }
  }

  if (isOn && isTimeUp()) {
    turnOff();
  }
}

void turnOn() {
  Serial.println("turnOn()");
  onAt = millis();
  isOn = true;
  analogWrite(LED_PIN, 255);
}

void turnOff() {
  Serial.println("turnOff()");
  isOn = false;
  analogWrite(LED_PIN, 0);
}

boolean isTimeUp() {
  return (millis() - onAt) >= onTime;
}



