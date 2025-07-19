#ifndef SPEEDKNOB_H
#define SPEEDKNOB_H

#include <stdint.h>

void speedKnob_init(uint8_t pin, int upperLimit);

/**
 * @brief Reads the current position of the knob
 * @return The current position from 0-100
 */
int speedKnob_readPosition();

#endif // SPEEDKNOB_H