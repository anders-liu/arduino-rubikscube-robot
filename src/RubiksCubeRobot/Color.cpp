//
// Color.cpp
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#include "Color.h"

uint16_t toRgb565(const RgbColor &color)
{
    return ((color.r & B11111000) << 8) |
           ((color.g & B11111100) << 3) |
           (color.b >> 3);
}
