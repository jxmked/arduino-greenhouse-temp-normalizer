#include "TimeInterval.h"
#include <Arduino.h>


TimeInterval::TimeInterval(unsigned long interval, unsigned long offset,bool autoUpdate):
  interval(interval),
  autoUpdate(autoUpdate),
  lastTime(0),
  time(0),
  offset(offset) {
    update();
    lastTime = time;
  }

void TimeInterval::update() {
  time = millis() + offset;
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
