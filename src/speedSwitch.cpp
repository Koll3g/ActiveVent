#include <speedSwitch.h>
#include <Arduino.h>

#define SPEEDSWITCH_PORT 8

void speedSwitch_init(){
    pinMode(SPEEDSWITCH_PORT,INPUT);
}

bool speedSwitch_ignoreSpeedKnob(){
    return digitalRead(SPEEDSWITCH_PORT);
}