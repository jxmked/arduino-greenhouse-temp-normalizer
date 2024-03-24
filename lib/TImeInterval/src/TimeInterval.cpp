#include "TimeInterval.h"
#include <Arduino.h>


TimeInterval::TimeInterval(unsigned long interval, bool autoUpdate):
  interval(interval),
  autoUpdate(autoUpdate),
  lastTime(0),
  time(0) {
    update();
    lastTime = time;
  }

void TimeInterval::update() {
  time = millis();
}

bool TimeInterval::marked() {
  if(autoUpdate) update();

  if(time - lastTime >= interval) {
    lastTime = time;
    return true;
  }

  return false;
}