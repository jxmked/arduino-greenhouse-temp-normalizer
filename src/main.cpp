#include <Arduino.h>
#include "Button.h"

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,2,16);

//LiquidCrystal_I2C lcd(0x27, 2, 16);


void lcdHandler();

int counter = 0;
Button plus(2);
Button minus(4);

void setup() {
  lcd.begin(2, 16);
  lcd.backlight();

  plus.begin();
  plus.set_repeat(500, 200);

  minus.begin();
  minus.set_repeat(500, 200);

}

void loop()
{

  if(plus.pressed()){
    counter++;

  }

  if(minus.pressed()) {
    counter--;
  }

  lcdHandler();
  yield();
}


void lcdHandler() {
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print(counter);

  delay(100);
}
