#include "SInitial.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "../BaseScreen.h"
#include "TimeInterval.h"
#include "Helpers.h"
#include "LCD_META.h"

#define __SINITIAL_TEXT_A "GROUP 10 - AVT"
#define __SINITIAL_TEXT_B "S.Y. 2023-2024"
#define __SINITIAL_INTERVAL 3000 // Display for 3 sec

SInitial::SInitial() : BaseScreen(INITIAL, __SINITIAL_INTERVAL),
                       TXT_A(__SINITIAL_TEXT_A),
                       TXT_B(__SINITIAL_TEXT_B),
                       isVisible(true)
{
}

void SInitial::update(unsigned long ms)
{
}

void SInitial::display(LiquidCrystal_I2C LCD)
{
  if (!isVisible)
    return;

  const auto txt_a_pos = centerText(TXT_A.length(), LCD_META.rows);
  const auto txt_b_pos = centerText(TXT_B.length(), LCD_META.rows);

  LCD.setCursor(txt_a_pos, 0);
  LCD.print(TXT_A);

  LCD.setCursor(txt_b_pos, 1);
  LCD.print(TXT_B);
}
