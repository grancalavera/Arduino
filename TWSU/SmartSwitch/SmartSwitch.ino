#include <Bounce.h>

/*
  A switch that toggles a LED on and off. The LED will turn off by itself after
  a time interval.
*/
#include <Bounce.h>

const int BUTTON_PIN  = 2;
const int LED_PIN     = 10;

Bounce button         = Bounce(BUTTON_PIN, 100);
int buttonState       = LOW;
int onTime            = 5000;
int onAt              = 0;
int dimmSteps         = 20000;
int dimmStep          = 0;

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

void loop() {
  if (button.update()) {
    buttonState = button.read();
    if (buttonState == HIGH) {
      if (!isOn) turnOn();
      else turnOff(true);
    }
  }
  if (isOn && isTimeUp()) turnOff(false);
  if (isDimming) dimm();
}

void turnOn() {
  onAt = millis();
  isOn = true;
  isDimming = false;
  analogWrite(LED_PIN, 255);
}

void turnOff(boolean hard) {
  isOn = false;
  if (hard) {
    turnOffHard();
  } else {
    dimmStep = 0;
    dimm();
  }
}

void turnOffHard() {
  isDimming = false;
  analogWrite(LED_PIN, 0);
}

boolean isTimeUp() {
  return (millis() - onAt) >= onTime;
}

void dimm() {
  isDimming = true;
  analogWrite(LED_PIN, map(dimmStep, 0, dimmSteps, 255, 0));
  dimmStep ++;
  if (dimmStep >= dimmSteps) {
    turnOffHard();
  }
}

