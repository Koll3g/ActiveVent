#include <speedKnob.h>
#include <Arduino.h>

static uint8_t speedKnob_readPin;
static int speedKnob_upperLimit;

void speedKnob_init(uint8_t pin, int upperLimit){
    speedKnob_readPin = pin;
    speedKnob_upperLimit = upperLimit;
}

int speedKnob_readPosition(){
    uint32_t rawPosition = analogRead(speedKnob_readPin);
    return (rawPosition * 100 / speedKnob_upperLimit);
}
