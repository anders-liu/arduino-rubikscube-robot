//
// Color.h
//
// Define functions for manipulating colors.
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#pragma once

#include <Arduino.h>

struct RgbColor
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

uint16_t toRgb565(const RgbColor &color);
