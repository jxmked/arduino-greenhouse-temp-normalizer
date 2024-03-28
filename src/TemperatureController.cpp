#include "TemperatureController.h"
#include "Arduino.h"


TemperatureController::TemperatureController() :
  temperature(0),
  humidity(0),
  threshold(0) { }

void TemperatureController::begin() { }

void TemperatureController::setThreshold(int thres) {
  threshold = thres;
}

void TemperatureController::setTempHumd(float t, float h) {
  temperature = t;
  humidity = h;
}

void TemperatureController::update(unsigned long ms) { }

bool TemperatureController::isThresholdExceed() {
  return (temperature >= threshold);
}