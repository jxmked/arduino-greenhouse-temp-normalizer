#include <Arduino.h>
#include "DEFINITION.h"
#include "SBoot.h"
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "../BaseScreen.h"
#include "TimeInterval.h"
#include "Helpers.h"
#include "LCD_META.h"

#if USE_BLOCK_BOOT
#define __BOOT_TEXT "LOADING: "
#else
#define __BOOT_TEXT "LOADING"
#endif

#define __BOOT_INTERVAL 3000      // Display for 3 sec
#define __BOOT_BLINK_INTERVAL 800 // 800 ms

SBoot::SBoot() : BaseScreen(E_PROGRAM_STATE::BOOT, __BOOT_INTERVAL), BOOT_TXT(__BOOT_TEXT),
BLINK_PROG(__BOOT_BLINK_INTERVAL, 0, true),
isVisible(true),
loading_value(0) { }

void SBoot::update(unsigned long ms) {
  isVisible = !BLINK_PROG.marked(1000);

  const auto a = ms - initialMs;
  const float b = float(a) / (screenInterval - 500);

  loading_value = round(b * 100);

  if (loading_value > 100)
    loading_value = 100;
}

void SBoot::display(LiquidCrystal_I2C LCD) {

#if USE_BLOCK_BOOT
  // For Second Row
  const int blockCount = 16 * (float(loading_value) / 100);

  LCD.clear();

  // Row 1
  if (isVisible) {
    LCD.setCursor(1, 0);
    LCD.print(BOOT_TXT);
  }

  LCD.setCursor(10, 0);
  LCD.print(loading_value);
  LCD.print("%");
  // End Row 1

  // Row 2
  LCD.setCursor(0, 1);
  for (int i = 0; i < blockCount; i++) {
    LCD.write(byte(0));
  }
  // End Row 2
#else
  // Length of a number.
  // I have tried to convert number to string
  // but fail multiple times. I can't find any
  // options to try and went to this.
  unsigned long numLen = 3;

  if (loading_value < 10) {
    numLen = 1;
  } else if (loading_value > 9 && loading_value < 100) {
    numLen = 2;
  }

  const auto percentCursor = centerText(numLen + 1, LCD_META.rows);
  const auto centered = centerText(BOOT_TXT.length(), LCD_META.rows);

  LCD.clear();

  if (isVisible) {
    LCD.setCursor(centered, 0);
    LCD.print(BOOT_TXT);
  }

  LCD.setCursor(percentCursor, 1);
  LCD.print(loading_value);
  LCD.print("%");
#endif
}
