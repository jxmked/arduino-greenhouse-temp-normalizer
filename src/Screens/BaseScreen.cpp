#include "BaseScreen.h"
#include <Arduino.h>

#include <E_PROGRAM_STATE.h>

BaseScreen::BaseScreen(E_PROGRAM_STATE targetState, LiquidCrystal_I2C LCD) : targetState(targetState),
LCD(LCD)
{
}
void BaseScreen::update(void)
{
}

void BaseScreen::display(void)
{
}
