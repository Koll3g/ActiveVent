#include <Arduino.h>
#include <speedKnob.h>
#include <fan.h>
#include <speedSwitch.h>

// #define DEBUG_ON

void fanControl();

void setup() {
  #ifdef DEBUG_ON
    Serial.begin(9600);
  #endif
  
  fan_init();
  speedSwitch_init();
}

void loop() {
  fanControl();
  delay(500);
}

void fanControl(){
  if(speedSwitch_ignoreSpeedKnob()){
    fan_setSpeed(speedKnob_readPosition());
  }
  else{
    fan_setSpeed(100);
  }

  #ifdef DEBUG_ON
    Serial.print("Knob: ");
    Serial.print(speedKnob_readPosition());
    Serial.print(" | RPM: ");
    Serial.print(fan_getRpm());
    Serial.print(" | Switch: ");
    Serial.println(speedSwitch_ignoreSpeedKnob());
  #endif
}

