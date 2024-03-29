#include <Arduino.h>
#include "BrightnessAuto.h"
#include "E_SCREEN_META.h"
#include "Helpers.h"

BrightnessAuto::BrightnessAuto() :
  temp(0),
  humd(0),
  threshold(0),
  brightness(0),
  meta(E_SCREEN_META::AUTO),
  nearBright(1),
  lastIntervalA(0),
  onAnimate(false),
  onIncrease(false) {

}

void BrightnessAuto::update(unsigned long ms) {
  if (!onAnimate)
    lastIntervalA = ms;


  if (temp + nearBright >= threshold) {
    onAnimate = true;

    auto a = static_cast<double>(ms - lastIntervalA);
    const auto b = static_cast<double>(TRANSITION_INTERVAL);

    if (a >= b) {
      a = b;
    }

    brightness = round(100 * transitionSwing(a / b));
  } else {
    onAnimate = false;

  }
}
