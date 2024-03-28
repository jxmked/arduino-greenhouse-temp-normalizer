#include "Helpers.h"

#include <Arduino.h>

uint8_t centerText(uint8_t textLength, uint8_t maxTextWidth) {

  if (maxTextWidth - textLength == 2)
    return 1;

  const uint8_t half_text_width = maxTextWidth / 2;
  const uint8_t half_text_length = textLength / 2;
  const uint8_t absValue = abs(half_text_width - half_text_length);

  return (absValue <= 0) ? 0 : absValue - 1;
}

bool isDiffAchieved(unsigned long currentMs, unsigned long lastMs, unsigned long targetDiff) {
  return getMillisDiff(currentMs, lastMs) >= targetDiff;
}

unsigned long getMillisDiff(unsigned long currentMs, unsigned long lastMs) {
  return currentMs - lastMs;
}
