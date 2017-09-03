//
// Program.cpp
//
// Copyright Anders Liu.
//
// For more information, visit https://github.com/anders-liu/arduino-rubikscube-robot
//

#include <Wire.h>
#include "Program.h"
#include "Pwm.h"
#include "Screen.h"
#include "UI.h"

void Program_setup()
{
    Serial.begin(9600);
    Serial.println("Starting...");

    Wire.begin();
    Pwm_setup();

    delay(1500);
    Screen_setup();

    UI_enterStartWin();
    Serial.println("Started.");
}

void Program_loop()
{
}
