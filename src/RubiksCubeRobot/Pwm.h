//
// Pwm.h
//
// Define functions for manipulating PCA9685 PWM controller.
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#pragma once

#include <Arduino.h>

// Wiring
#define PWM_ADDR 0x40
#define PWM_OE_PIN 12

void Pwm_setup();
void Pwm_write(uint8_t channel, uint16_t value);
