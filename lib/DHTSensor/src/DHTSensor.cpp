#include <Arduino.h>

#include <dht11.h>
#include "DHTSensor.h"


dht11 dht_sensor;


DHTSensor::DHTSensor(uint8_t pin):
  pin(pin),
  current_hum(0),
  current_temp(0) {
  
}

void DHTSensor::update() {
  dht_sensor.read(pin);
  current_hum = (float) dht_sensor.humidity;
  current_temp = (float) dht_sensor.temperature;
}

float DHTSensor::temperature() {
  return current_temp;
}

float DHTSensor::humidity() {
  return current_hum;
}