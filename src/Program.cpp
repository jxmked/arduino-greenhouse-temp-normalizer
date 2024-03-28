#include "Program.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "TimeInterval.h"
#include "Helpers.h"
#include "LCD_META.h"

// Will include all screen files
#include "Screens/index.cpp"

#define DEFAULT_THRESHOLD 34

LiquidCrystal_I2C lcd(LCD_META.addr, LCD_META.rows, LCD_META.cols);

// Screen Text Definition.
// We need to define it as constant String type
// So we can get the length method

TimeInterval lcd_hz(200, 0, true);

/**
 * Screens
 */
SShow_Thres *__showthres__ = new SShow_Thres();

BaseScreen *screens[] = {
    __showthres__,
    new SBoot(),
    new SInitial(),
    new SHome()};

const int screenLength = sizeof(screens) / sizeof(screens[0]);

/** END SCREENS */

unsigned long _lastTime = 0;
E_PROGRAM_STATE _timeOwner = PRESET;
E_PROGRAM_STATE _lastTimeOwner = PRESET;

// calling every screen as first boot since the currentFirst has been change
bool firstCalled = true;
E_PROGRAM_STATE currentFirst = BOOT;

Program::Program() : state(BOOT),
                     currentInterval(0)
{
}

void Program::begin()
{
  lcd.begin(LCD_META.rows, LCD_META.cols);
  lcd.backlight();

  __showthres__->threshold = DEFAULT_THRESHOLD;
}

void Program::show_threshold(unsigned long inMs)
{
  state = SHOW_THRESHOLD;
  currentInterval = millis();
}

void Program::pressEnter()
{
  state = SHOW_THRESHOLD;
  _lastTime = millis();
}
void Program::pressDecrease()
{
}
void Program::pressIncrease()
{
}
void Program::update()
{

  // Always Update Our Sensor Even in the Background
  screens[3]->update(millis());

  for (int index = 0; index < screenLength; index++)
  {
    BaseScreen &scr = *screens[index];

    if (scr.targetState != state)
      continue;

    scr.update(millis());
    break;
  }

  switch (state)
  {
  case BOOT:
    _timeOwner = BOOT;

    if (_timeOwner != _lastTimeOwner)
    {
      _lastTimeOwner = BOOT;
      _lastTime = millis();
    }

    if (isDiffAchieved(millis(), _lastTime, screens[1]->screenInterval))
    {
      state = INITIAL;
    }

    break;

  case INITIAL:
    _timeOwner = INITIAL;

    if (_timeOwner != _lastTimeOwner)
    {
      _lastTimeOwner = INITIAL;
      _lastTime = millis();
    }

    if (isDiffAchieved(millis(), _lastTime, screens[2]->screenInterval))
    {
      state = SHOW_THRESHOLD;
    }
    break;

  case HOME:
    break;

  case SHOW_THRESHOLD:
    _timeOwner = SHOW_THRESHOLD;

    if (_timeOwner != _lastTimeOwner)
    {
      _lastTimeOwner = SHOW_THRESHOLD;
      _lastTime = millis();
    }

    if (isDiffAchieved(millis(), _lastTime, screens[0]->screenInterval))
    {
      state = HOME;
    }

    break;

  default:
    break;
  }
}
void Program::display()
{
  if (!lcd_hz.marked())
    return;

  lcd.clear();

  for (int index = 0; index < screenLength; index++)
  {
    BaseScreen &scr = *screens[index];

    if (scr.targetState != state)
      continue;

    scr.display(lcd);
    break;
  }
}

E_PROGRAM_STATE Program::getState()
{
  return state;
}
