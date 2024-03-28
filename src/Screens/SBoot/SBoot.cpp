#include "SBoot.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "../BaseScreen.h"
#include "TimeInterval.h"
#include "Helpers.h"
#include "LCD_META.h"

#define __BOOT_TEXT "LOADING"
#define __BOOT_INTERVAL 3000      // Display for 3 sec
#define __BOOT_BLINK_INTERVAL 800 // 800 ms

SBoot::SBoot() : BaseScreen(BOOT, __BOOT_INTERVAL), BOOT_TXT(__BOOT_TEXT),
                 BLINK_PROG(__BOOT_BLINK_INTERVAL, 0, true),
                 isVisible(true)
{
}

void SBoot::update(unsigned long ms)
{
  isVisible = !BLINK_PROG.marked(1000);
}

void SBoot::display(LiquidCrystal_I2C LCD)
{
  if (!isVisible)
     return;

  const auto centered = centerText(BOOT_TXT.length(), LCD_META.rows);

  LCD.setCursor(centered, 0);
  LCD.print(BOOT_TXT);
}
