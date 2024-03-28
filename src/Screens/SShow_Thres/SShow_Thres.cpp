#include "SShow_Thres.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "../BaseScreen.h"
#include "LCD_META.h"
#include "Helpers.h"
#include <String.h>

#define __THRES_TEXT "THRESHOLD"

SShow_Thres::SShow_Thres() : BaseScreen(SHOW_THRESHOLD, 0),
                             threshold(0),
                             isVisible(true),
                             txt(__THRES_TEXT)
{
}

void SShow_Thres::update(unsigned long ms)
{
}

void SShow_Thres::display(LiquidCrystal_I2C lcd)
{
  if (!isVisible)
    return;

  const int thres = threshold;
  const auto num_cursor = centerText(4, LCD_META.rows);
  const auto cursor = centerText(txt.length(), LCD_META.rows);

  lcd.setCursor(cursor, 0);
  lcd.print(txt);

  lcd.setCursor(num_cursor, 1);

  if (thres < 10)
    lcd.print("0"); // Add zero at the beginning if the number is lessthan 10
  lcd.print(thres);
  lcd.print((char)223);
  lcd.print("C");
}
