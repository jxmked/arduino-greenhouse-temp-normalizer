#include "Program.h"
#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

#include "TimeInterval.h"

// Liquid Crystal I2C Definition
#define LCD_WIDTH 16
#define LCD_HEIGHT 2


#define BOOT_INTERVAL 3000 // 3 sec

LiquidCrystal_I2C lcd(0x27, LCD_HEIGHT, LCD_WIDTH);

// Screen Text Definition.
// We need to define it as constant String type
// So we can get the length method

const String BOOT_TEXT = "LOADING";

TimeInterval lcd_hz(200, true);
TimeInterval BOOT_BLINK(1000, true);

Program::Program() : status(BOOT),
                     currentInterval(0)
{
}

void Program::begin() {
  lcd.begin(LCD_HEIGHT, LCD_WIDTH);
  lcd.backlight();
}

unsigned long Program::getMillis()
{
  return millis();
}
unsigned long Program::getDiffMillis(unsigned long fromMs)
{
  return getMillis() - fromMs;
}

void Program::show_threshold(unsigned long inMs)
{
  status = SHOW_THRESHOLD;
  currentInterval = getMillis();
}

void Program::pressEnter()
{
}
void Program::pressDecrease()
{
}
void Program::pressIncrease()
{
}
void Program::update()
{
}
void Program::display()
{
  if(!lcd_hz.marked()) return;

  lcd.clear();

  switch (status)
  {
  case BOOT:
    showBoot();
    break;
  
  default:
    break;
  }
}

void Program::showBoot()
{
  if(!BOOT_BLINK.marked(1000)) return;

  // Lets center this string
  const uint8_t half_width = LCD_WIDTH / 2;
  const uint8_t half_string = round(BOOT_TEXT.length() / 2);

  lcd.setCursor(abs(half_width - half_string), 0);
  lcd.print(BOOT_TEXT);
 // lcd.print(abs(half_width - half_string));
}

E_PROGRAM_STATE Program::getStatus()
{
  return status;
}