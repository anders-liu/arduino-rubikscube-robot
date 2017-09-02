//
// Screen.h
//
// Define functions for manipulating ILI9341 based resistive touch screen.
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#pragma once

#include <Arduino.h>
#include "Color.h"

#define SCREEN_WIDTH ((uint16_t)320)
#define SCREEN_HEIGHT ((uint16_t)240)

extern RgbColor Screen_backColor;
extern RgbColor Screen_foreColor;
extern uint8_t Screen_textScale;

void Screen_setup();
void Screen_fillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void Screen_drawText(uint16_t x, uint16_t y, const char *str);
