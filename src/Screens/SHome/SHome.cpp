#include "SHome.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "../BaseScreen.h"
#include "Helpers.h"
#include "LCD_META.h"

SHome::SHome() : BaseScreen(E_PROGRAM_STATE::HOME, 1),
isVisible(true),
temperature(0),
humidity(0) { }

void SHome::update(unsigned long ms) { }

void SHome::display(LiquidCrystal_I2C lcd) {
  if (!isVisible)
    return;

  const auto ta = centerText(14, LCD_META.rows);
  const auto tb = centerText(14, LCD_META.rows);

  lcd.setCursor(ta, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(tb, 1);
  lcd.print("Humd: ");
  lcd.print(humidity);
  lcd.print("%");
}

void SHome::updateReadings(float temp, float humd) {
  temperature = temp;
  humidity = humd;
}
