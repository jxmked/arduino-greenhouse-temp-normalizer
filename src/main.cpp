#include <Arduino.h>

#include <Wire.h>
#include <dht11.h>

#include <LiquidCrystal_I2C.h>

#include "../lib/Button.cpp"

dht11 dht;

#define dht_pin A0


LiquidCrystal_I2C lcd(0x27, 2, 16);


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
