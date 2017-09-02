//
// UI.h
//
// Define UI functions.
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#pragma once

#include <Arduino.h>
#include "Color.h"

extern const RgbColor UI_color_startWin PROGMEM;
extern const RgbColor UI_color_startTitleFore PROGMEM;
extern const RgbColor UI_color_startTitleBack PROGMEM;
extern const RgbColor UI_color_startSignature PROGMEM;
extern const RgbColor UI_color_startPrompt PROGMEM;

extern const RgbColor UI_color_servoWin PROGMEM;
extern const RgbColor UI_color_servoBtn PROGMEM;
extern const RgbColor UI_color_servoBtnActive PROGMEM;
extern const RgbColor UI_color_servoText PROGMEM;

void UI_enterStartWin();
void UI_enterMainWin();
void UI_enterServoWin();
