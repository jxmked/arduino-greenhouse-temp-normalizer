#include "Program.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "TimeInterval.h"
#include "Helpers.h"
#include "LCD_META.h"

// Will include all screen files
#include "Screens/index.cpp"

int THRESHOLD = 34;

LiquidCrystal_I2C lcd(LCD_META.addr, LCD_META.rows, LCD_META.cols);

// Screen Text Definition.
// We need to define it as constant String type
// So we can get the length method

TimeInterval lcd_hz(200, 0, true);

/**
 * Screens
 */
SShow_Thres* __showthres__ = new SShow_Thres();

BaseScreen* screens[] = {
    __showthres__,
    new SBoot(),
    new SInitial(),
    new SHome() };

const int screenLength = sizeof(screens) / sizeof(screens[0]);

/** END SCREENS */

unsigned long _lastTime = 0;
E_PROGRAM_STATE _timeOwner = E_PROGRAM_STATE::PRESET;
E_PROGRAM_STATE _lastTimeOwner = E_PROGRAM_STATE::PRESET;

// calling every screen as first boot since the currentFirst has been change
bool firstCalled = true;
E_PROGRAM_STATE currentFirst = E_PROGRAM_STATE::BOOT;

// Deny all button actions during boot...
bool isReady = false;

Program::Program() : state(E_PROGRAM_STATE::BOOT),
currentInterval(0) { }

void Program::begin() {
  lcd.begin(LCD_META.rows, LCD_META.cols);
  lcd.backlight();

  __showthres__->threshold = DEFAULT_THRESHOLD;

  const auto initialMillis = millis();

  for (int index = 0; index < screenLength; index++) {
    BaseScreen& scr = *screens[index];

    scr.begin(initialMillis);
  }
}

void Program::show_threshold(unsigned long ms) {
  state = E_PROGRAM_STATE::SHOW_THRESHOLD;
  _lastTime = ms;
}

void Program::pressEnter() {
  if (!isReady) return;

  show_threshold(millis());
}
void Program::pressDecrease() {
  if (!isReady) return;

}
void Program::pressIncrease() {
  if (!isReady) return;

}
void Program::update() {
  const auto ms = millis();

  // Always Update Our Sensor Even in the Background
  screens[3]->update(ms);

  for (int index = 0; index < screenLength; index++) {
    BaseScreen& scr = *screens[index];

    if (scr.targetState != state)
      continue;

    scr.update(ms);
    break;
  }

  switch (state) {
  case E_PROGRAM_STATE::BOOT:
    _timeOwner = E_PROGRAM_STATE::BOOT;

    if (_timeOwner != _lastTimeOwner) {
      _lastTimeOwner = E_PROGRAM_STATE::BOOT;
      _lastTime = millis();
    }

    if (isDiffAchieved(millis(), _lastTime, screens[1]->screenInterval)) {
      state = E_PROGRAM_STATE::INITIAL;
    }

    break;

  case E_PROGRAM_STATE::INITIAL:
    _timeOwner = E_PROGRAM_STATE::INITIAL;

    if (_timeOwner != _lastTimeOwner) {
      _lastTimeOwner = E_PROGRAM_STATE::INITIAL;
      _lastTime = millis();
    }

    if (isDiffAchieved(millis(), _lastTime, screens[2]->screenInterval)) {
      state = E_PROGRAM_STATE::SHOW_THRESHOLD;
    }

    break;

  case E_PROGRAM_STATE::HOME:
    isReady = true;

    break;

  case E_PROGRAM_STATE::SHOW_THRESHOLD:
    _timeOwner = E_PROGRAM_STATE::SHOW_THRESHOLD;

    if (_timeOwner != _lastTimeOwner) {
      _lastTimeOwner = E_PROGRAM_STATE::SHOW_THRESHOLD;
      _lastTime = millis();
    }

    if (isDiffAchieved(millis(), _lastTime, screens[0]->screenInterval)) {
      state = E_PROGRAM_STATE::HOME;
    }

    break;

  default:
    break;
  }
}
void Program::display() {
  if (!lcd_hz.marked())
    return;

  lcd.clear();

  for (int index = 0; index < screenLength; index++) {
    BaseScreen& scr = *screens[index];

    if (scr.targetState != state)
      continue;

    scr.display(lcd);
    break;
  }
}

E_PROGRAM_STATE Program::getState() {
  return state;
}
