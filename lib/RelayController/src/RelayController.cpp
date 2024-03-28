#include "RelayController.h"
#include <Arduino.h>
#include "Helpers.h"

RelayController::RelayController(uint8_t pin) :
  pin(pin),
  mode(RelayControllerMode::INACTIVE),
  testInterval(0),
  testMs(0) { }

void RelayController::begin(void) {
  pinMode(pin, OUTPUT);
  deactivate();
}

void RelayController::update(unsigned long ms) {
  switch (mode) {
  case RelayControllerMode::INACTIVE:
    digitalWrite(pin, INACTIVE);
    break;

  case RelayControllerMode::ACTIVE:
    digitalWrite(pin, ACTIVE);
    break;

  case RelayControllerMode::TEST:
    digitalWrite(pin, ACTIVE);

    if (isDiffAchieved(ms, testMs, testInterval)) {
      mode = RelayControllerMode::INACTIVE;
    }
    break;
  default:
    break;
  }
}

void RelayController::run_test(unsigned long interval) {
  testInterval = interval;
  mode = RelayControllerMode::TEST;
}

void RelayController::activate(void) {
  mode = RelayControllerMode::ACTIVE;
}

void RelayController::deactivate(void) {
  mode = RelayControllerMode::INACTIVE;
}

RelayControllerMode RelayController::getMode(void) {
  return mode;
}

void RelayController::setTestMs(unsigned long ms) {
  testMs = ms;
}