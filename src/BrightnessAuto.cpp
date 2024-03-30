#include <Arduino.h>
#include "BrightnessAuto.h"
#include "E_SCREEN_META.h"
#include "Helpers.h"

BrightnessAuto::BrightnessAuto() :
  temp(0),
  humd(0),
  threshold(0),
  targetBright(100),
  meta(E_SCREEN_META::AUTO),
  brightness(0),
  nearBright(1),
  lastms(0),
  _lastValue(targetBright) {

}

void BrightnessAuto::begin(unsigned long ms) {
  lastms = ms;
}

void BrightnessAuto::update(unsigned long ms) {

  if (brightness != targetBright) {
    transistionBrightness(ms);
    brightness = round(_lastValue);
  }
}

bool BrightnessAuto::isNearThreshold(float temp) {
  return false;
}

void BrightnessAuto::transistionBrightness(unsigned long ms) {
  const long ellapse = ms - lastms;

  if (ellapse >= DURATION) {
    _lastValue = float(targetBright);
  } else {
    const float delta = float(targetBright) - _lastValue;
    _lastValue = _lastValue + (delta * float(ellapse) / float(DURATION));

    if (targetBright == 0) {
      if (abs(_lastValue) < 2) {
        _lastValue = 0.0;
      }
    } else {
      if (abs(_lastValue) > 98) {
        _lastValue = 100.0;
      }
    }

    if (abs(_lastValue) == targetBright) {
      lastms = ms - 100;
    }
  }
}




