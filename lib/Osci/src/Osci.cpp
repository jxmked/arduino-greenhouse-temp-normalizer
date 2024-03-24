#include "Osci.h"
#include <Arduino.h>
#include <math.h>



Osci::Osci(long interval):
  interval(interval) {

  }

float Osci::value() {
  return sineWave();
}

bool Osci::isHigh() {
  return (sineWave() > 0.5);
}

bool Osci::isLow() {
  return sineWave() <= 0.5;
}

float Osci::sineWave() {
  long ms = (long) millis();

  float s = sin(TWO_PI * (ms % interval) / interval);

  return (s + 1.0) / 2.0; // Normalize
}