#ifndef Helpers_h
#define Helpers_h


#include "Arduino.h"

uint8_t centerText(uint8_t textLength, uint8_t maxTextWidth);
bool isDiffAchieved(unsigned long currentMs, unsigned long lastMs, unsigned long targetDiff);
unsigned long getMillisDiff(unsigned long currentMs, unsigned long lastMs);


#endif