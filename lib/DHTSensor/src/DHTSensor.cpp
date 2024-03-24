#include <Arduino.h>

#include <dht11.h>
#include "DHTSensor.h"
#include "TimeInterval.h"

dht11 dht_sensor;

/**
 * unsigned long hz - must be greater than 1000
*/
DHTSensor::DHTSensor(uint8_t pin, unsigned long hz) : pin(pin),
                                                      current_hum(0),
                                                      current_temp(0),
                                                      hz(hz),
                                                      timeInterval(hz)
{
}

unsigned long DHTSensor::currentMillis()
{
  return millis();
}

void DHTSensor::update()
{
  timeInterval.update();
  if (timeInterval.marked())
    return;

  dht_sensor.read(pin);
  current_hum = (float)dht_sensor.humidity;
  current_temp = (float)dht_sensor.temperature;
}

float DHTSensor::temperature()
{
  return current_temp;
}

float DHTSensor::humidity()
{
  return current_hum;
}
