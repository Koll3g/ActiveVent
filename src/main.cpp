#include <Arduino.h>
#include <speedKnob.h>
#include <fan.h>

void setup() {
  Serial.begin(9600);
  speedKnob_init(PIN_A0,1023);
  fan_init();
  pinMode(PIN7,OUTPUT);
  digitalWrite(PIN7,HIGH);
}

void loop() {
  int speedKnobPosition = speedKnob_readPosition();
  Serial.print("Knob: ");
  Serial.println(speedKnobPosition);
  fan_setSpeed(speedKnobPosition);
  Serial.print("RPM: ");
  Serial.println(fan_getRpm());
  delay(500);
}
