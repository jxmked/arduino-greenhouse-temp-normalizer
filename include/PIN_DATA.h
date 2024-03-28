#ifndef PIN_DATA_h
#define PIN_DATA_h

#include "Arduino.h"

struct PIN_DATA_T
{
  uint8_t DHT_Sensor = A0;
};

const PIN_DATA_T PIN_DATA;


#endif