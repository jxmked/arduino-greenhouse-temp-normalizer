#include <Arduino.h>
#include "Button.h"

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,2,16);

//LiquidCrystal_I2C lcd(0x27, 2, 16);


int counter = 0;
Button plus(2);
Button minus(4);

void setup() {
  lcd.begin(2, 16);
  lcd.backlight();

  plus.init();
  minus.init();

}

void loop()
{

  plus.update();
  minus.update();

  if(plus.isPressed()) {
    counter++;

  }

  if(minus.isPressed()) {
    counter--;
  }



  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print(counter);
  
  delay(100);
}
