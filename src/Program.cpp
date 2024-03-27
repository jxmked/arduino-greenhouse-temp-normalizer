#include "Program.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "TimeInterval.h"
#include "Helpers.h"

// Will include all screen files
#include "Screens/index.cpp"


// Liquid Crystal I2C Definition
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

LiquidCrystal_I2C lcd(0x27, LCD_HEIGHT, LCD_WIDTH);

// Screen Text Definition.
// We need to define it as constant String type
// So we can get the length method

TimeInterval lcd_hz(200, true);

/**
 * Screens
*/


/** BOOT ANIMATION */
const String BOOT_TEXT = "LOADING";
const unsigned long BOOT_INTERVAL = 3000; // 3 sec
TimeInterval BOOT_BLINK(800, true);

void showBoot();

/** END BOOT ANIMATION */


/** INITIAL ANIMATION */
const String INITIAL_TEXT_A = "GROUP 10 - AVT";
const String INITIAL_TEXT_B = "S.Y. 2023-2024";
const unsigned long INITIAL_INTERVAL = 5000; // 5 sec

void showInitial();

/** END INITIAL ANIMATION */

unsigned long _lastTime = 0;
E_PROGRAM_STATE _timeOwner = PRESET;
E_PROGRAM_STATE _lastTimeOwner = PRESET;

Program::Program() : status(BOOT),
                     currentInterval(0)
{
}

void Program::begin()
{
  lcd.begin(LCD_HEIGHT, LCD_WIDTH);
  lcd.backlight();
}

unsigned long Program::getMillis()
{
  return millis();
}
unsigned long Program::getDiffMillis(unsigned long fromMs)
{
  return getMillis() - fromMs;
}

void Program::show_threshold(unsigned long inMs)
{
  status = SHOW_THRESHOLD;
  currentInterval = getMillis();
}

void Program::pressEnter()
{
}
void Program::pressDecrease()
{
}
void Program::pressIncrease()
{
}
void Program::update()
{

  switch (status)
  {
  case BOOT:
    _timeOwner = BOOT;

    if (_timeOwner != _lastTimeOwner)
    {
      _lastTimeOwner = BOOT;
      _lastTime = getMillis();
    }

    if (isDiffAchieved(getMillis(), _lastTime, BOOT_INTERVAL))
    {
      status = INITIAL;
    }

    break;

  case INITIAL:

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

  switch (status)
  {
  case BOOT:
    showBoot();
    break;

  case INITIAL:
    showInitial();
    break;

  default:
    break;
  }
}

E_PROGRAM_STATE Program::getStatus()
{
  return status;
}

/**
 * Screen Display
 */

void showBoot()
{
  if (!BOOT_BLINK.marked(1000))
    return;

  // Lets center this string
  const auto centered = centerText(BOOT_TEXT.length(), LCD_WIDTH);

  lcd.setCursor(centered, 0);
  lcd.print(BOOT_TEXT);
}

void showInitial() {
  const auto ta = centerText(INITIAL_TEXT_A.length(), LCD_WIDTH);
  const auto tb = centerText(INITIAL_TEXT_B.length(), LCD_WIDTH);

  lcd.setCursor(ta, 0);
  lcd.print(INITIAL_TEXT_A);

  lcd.setCursor(tb, 1);
  lcd.print(INITIAL_TEXT_B);
}