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

  if (isNearThreshold(temp)) {
    brightness = 100;
    return;
  }

  if (brightness != targetBright) {
    transistionBrightness(ms);
    brightness = min(100, max(0, round(_lastValue)));
  }

  // Keep updated
  if (round(_lastValue) == round(targetBright)) {
    lastms = ms - 10;
  }
}

bool BrightnessAuto::isNearThreshold(float temp) {
  if (temp >= threshold) return true;
  return false;
  //return (threshold <= temp + nearBright);
}

void BrightnessAuto::transistionBrightness(unsigned long ms) {
  const long ellapse = ms - lastms;

  if (ellapse >= DURATION) {
    _lastValue = float(targetBright);
  } else {
    const float delta = float(targetBright) - _lastValue;

    _lastValue = _lastValue + float(delta * (float(ellapse) / DURATION));

    if (targetBright == 0) {
      if (abs(_lastValue) < 2) {
        _lastValue = 0.0;
      }
    } else {
      if (abs(_lastValue) > 98) {
        _lastValue = 100.0;
      }
    }
  }
}




