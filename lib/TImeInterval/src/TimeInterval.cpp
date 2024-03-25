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

bool TimeInterval::marked(unsigned long holdMillis) {
  if(autoUpdate) update();
  
  const auto currentTime = time;
  const unsigned long diff = currentTime - lastTime;

  if(diff >= interval) {
    if(diff > holdMillis)
      lastTime = currentTime;
    return true;
  }

  return false;
}

void TimeInterval::reset() {
  lastTime = time;
}
