#ifndef LCD_META_h
#define LCD_META_h

#include "Arduino.h"

struct LCD_META_T {
  uint8_t cols = 2;
  uint8_t rows = 16;
  uint8_t addr = 0x27;
};

const LCD_META_T LCD_META;

#endif