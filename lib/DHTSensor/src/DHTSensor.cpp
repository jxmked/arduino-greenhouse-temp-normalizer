#include <Arduino.h>

#include <dht11.h>
#include "DHTSensor.h"

dht11 dht_sensor;

DHTSensor::DHTSensor(uint8_t pin, unsigned long hz) : pin(pin),
                                                             current_hum(0),
                                                             current_temp(0),
                                                             hz(hz)
{

  if (hz < DHTSensor_DEFAULT_HZ)
  {
    hz = DHTSensor_DEFAULT_HZ;
  }
}

unsigned long DHTSensor::currentMillis()
{
  return millis();
}

void DHTSensor::update()
{
  if (currentMillis() % hz != 0)
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
