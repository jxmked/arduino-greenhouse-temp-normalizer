#ifndef PIN_DATA_h
#define PIN_DATA_h

#include "Arduino.h"

struct PIN_DATA_T {
  uint8_t DHT_Sensor = A0;
  uint8_t Fan_Relay = 7;
  uint8_t PLUS_BTN = 2;
  uint8_t MINUS_BTN = 4;
  uint8_t ENTER_BTN = 3;
  uint8_t LCD_BACKLIGHT = 5;
};

const PIN_DATA_T PIN_DATA;

#endif