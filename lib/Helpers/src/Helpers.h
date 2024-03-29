#ifndef Helpers_h
#define Helpers_h


#include "Arduino.h"
#include <math.h>

uint8_t centerText(uint8_t textLength, uint8_t maxTextWidth);
bool isDiffAchieved(unsigned long currentMs, unsigned long lastMs, unsigned long targetDiff);
unsigned long getMillisDiff(unsigned long currentMs, unsigned long lastMs);

/**
 * Transition
*/
double transitionSwing(double t);

#endif