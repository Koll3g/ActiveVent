#include <Arduino.h>
#include <speedKnob.h>
#include <fan.h>

#define DEBUG_ON

void fanControl();

void setup() {
  #ifdef DEBUG_ON
    Serial.begin(9600);
  #endif
  
  fan_init();
}

void loop() {
  fanControl();
  delay(500);
}

void fanControl(){
  int speedKnobPosition = speedKnob_readPosition();
  fan_setSpeed(speedKnobPosition);

  #ifdef DEBUG_ON
    Serial.print("Knob: ");
    Serial.println(speedKnobPosition);
    Serial.print("RPM: ");
    Serial.println(fan_getRpm());
  #endif
}