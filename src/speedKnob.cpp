#include <speedKnob.h>
#include <Arduino.h>

static uint8_t speedKnob_readPin;
static int speedKnob_upperLimit;

#define SPEEDKNOB_PIN A0 
#define SPEEDKNOB_UPPERLIMIT 1023

int speedKnob_readPosition(){
    uint32_t rawPosition = analogRead(SPEEDKNOB_PIN);
    return (rawPosition * 100 / SPEEDKNOB_UPPERLIMIT);
}
