#include <speedKnob.h>
#include <Arduino.h>

#define SPEEDKNOB_PIN A0 
#define SPEEDKNOB_UPPERLIMIT 1023

int speedKnob_readPosition(){
    uint32_t rawPosition = analogRead(SPEEDKNOB_PIN);
    return (rawPosition * 100 / SPEEDKNOB_UPPERLIMIT);
}
