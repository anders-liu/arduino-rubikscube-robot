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

void Program_setup()
{
    Wire.begin();
    Pwm_setup();
}

void Program_loop()
{
}
