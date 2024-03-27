#include "BaseScreen.h"
#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <E_PROGRAM_STATE.h>

BaseScreen::BaseScreen(LiquidCrystal_I2C LCD, E_PROGRAM_STATE objectTargetState) : LCD(LCD),
                                                                                   targetState(objectTargetState)
{
}
void BaseScreen::update(void)
{
}

void BaseScreen::display(void)
{
}
