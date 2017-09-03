//
// UI.cpp
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#include "UI.h"
#include "Screen.h"

const RgbColor UI_color_startWin PROGMEM{0, 0, 0};
const RgbColor UI_color_startTitleFore PROGMEM{255, 255, 255};
const RgbColor UI_color_startTitleBack PROGMEM{244, 114, 17};
const RgbColor UI_color_startPrompt PROGMEM{255, 255, 0};

const RgbColor UI_color_servoWin PROGMEM{153, 217, 234};
const RgbColor UI_color_servoBtn PROGMEM{0, 162, 232};
const RgbColor UI_color_servoBtnActive PROGMEM{34, 177, 76};
const RgbColor UI_color_servoText PROGMEM{255, 242, 0};

void UI_enterStartWin()
{
    Screen_off();
    memcpy_P(&Screen_backColor, &UI_color_startWin, sizeof(RgbColor));
    Screen_fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    Screen_on();

    memcpy_P(&Screen_backColor, &UI_color_startTitleBack, sizeof(RgbColor));
    Screen_fillRect(10,10, 100, 100);
}

void UI_enterMainWin()
{
}

void UI_enterServoWin()
{
}
