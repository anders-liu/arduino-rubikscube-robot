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

// Wiring
#define SCREEN_PORT PORTF
#define SCREEN_PIN PINF
#define SCREEN_DDR DDRF
#define SCREEN_RST A9
#define SCREEN_CS A8
#define SCREEN_RS A10
#define SCREEN_WR A11
#define SCREEN_RD A12

#define SCREEN_WIDTH ((uint16_t)320)
#define SCREEN_HEIGHT ((uint16_t)240)

extern RgbColor Screen_backColor;
extern RgbColor Screen_foreColor;
extern uint8_t Screen_textScale;

void Screen_setup();
void Screen_off();
void Screen_on();
void Screen_fillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void Screen_drawText(uint16_t x, uint16_t y, const char *str);
