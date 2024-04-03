#include "DEFINITION.h"
#include <Arduino.h>
#include "BrightnessAuto.h"
#include "E_SCREEN_META.h"
#include "Helpers.h"

BrightnessAuto::BrightnessAuto() :
  temp(0),
  threshold(0),
  targetBright(100),
  meta(E_SCREEN_META::AUTO),
  brightness(0),
#if USE_ACTUAL_NEAR
  nearBright(1),
#endif
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
#if USE_ACTUAL_NEAR  
  return (threshold <= temp + nearBright);
#else
  return temp >= threshold;
#endif
}

void BrightnessAuto::transistionBrightness(unsigned long ms) {
  const long elapse = ms - lastms;
  const float maxDelta = float(elapse) / DURATION;
  const float delta = float(targetBright) - _lastValue;

  float clampedDelta = delta;

  if (abs(delta) > maxDelta) {
    clampedDelta = (delta > 0) ? maxDelta : -maxDelta;
  }

  _lastValue += clampedDelta;

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




