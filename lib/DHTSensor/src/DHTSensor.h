#ifndef DHTSensor_h
#define DHTSensor_h

#include "dht11.h"
#include "TimeInterval.h"

#define DHTSensor_DEFAULT_HZ 1000

class DHTSensor
{
public:
  DHTSensor(uint8_t pin, unsigned long hz = 1000);
  void update();
  float temperature();
  float humidity();

private:
  unsigned long currentMillis();

  uint8_t pin;
  float current_hum;
  float current_temp;
  unsigned long hz;
  TimeInterval timeInterval;
};

#endif
