#include "BaseScreen.h"
#include <Arduino.h>

#include <E_PROGRAM_STATE.h>

BaseScreen::BaseScreen(E_PROGRAM_STATE targetState, unsigned long scrIval) : targetState(targetState),

                                                                             screenInterval(scrIval)
{
}

void BaseScreen::begin(unsigned long initialMillis)
{
}

void BaseScreen::update(unsigned long ms)
{
}

void BaseScreen::display(LiquidCrystal_I2C lcd)
{
}

bool BaseScreen::isEndOfInterval(void)
{
  return false;
}
