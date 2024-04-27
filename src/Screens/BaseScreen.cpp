#include "BaseScreen.h"
#include <Arduino.h>

#include <E_PROGRAM_STATE.h>

BaseScreen::BaseScreen(E_PROGRAM_STATE targetState, unsigned long scrIval) : targetState(targetState),

screenInterval(scrIval),
initialMs(0),
_holdScreen(false) { }

void BaseScreen::begin(unsigned long initialMillis) {
    initialMs = initialMillis;
}

void BaseScreen::update(unsigned long ms) { }

void BaseScreen::display(LiquidCrystal_I2C lcd) { }

bool BaseScreen::isEndOfInterval(unsigned long ms) {
    return (ms - initialMs >= screenInterval);
}

bool BaseScreen::holdScreen() {
    return _holdScreen;
}