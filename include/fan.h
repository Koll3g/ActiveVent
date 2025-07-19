#ifndef FAN_H
#define FAN_H

#include <stdint.h>

void fan_init();

void fan_rpmInteruptHandler();
uint16_t fan_getRpm();

/**
 * @brief Set the speed from 0-100
 */
void fan_setSpeed(uint8_t speed);

#endif // FAN_H