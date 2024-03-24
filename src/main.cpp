#include <Arduino.h>
#include "Button.h"
#include "DHTSensor.h"
#include "TimeInterval.h"
#include <LiquidCrystal_I2C.h>
#include "Osci.h"


LiquidCrystal_I2C lcd(0x27, 2, 16);

#define P_SENSOR A0

void lcdHandler();

int counter = 0;
Button plus(2);
Button minus(4);

DHTSensor sensor(P_SENSOR);
TimeInterval errIval(500, true);
Osci er(2000);


void setup()
{
  lcd.begin(2, 16);
  lcd.backlight();

  plus.begin();
  plus.set_repeat(500, 200);

  minus.begin();
  minus.set_repeat(500, 200);

}

void loop()
{

  if(er.isHighest()) {
    
   // lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("ERROR");

  } else {
    lcd.clear();
  }


 // delay(10);



  return;

  sensor.update();

  if (plus.pressed())
  {
    counter++;
  }

  if (minus.pressed())
  {
    counter--;
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(counter);

  analogWrite(6, counter);

  delay(500);

 // lcdHandler();
}

void lcdHandler()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(sensor.temperature());
  lcd.print((char)223);
  lcd.printstr("Cel");

  lcd.setCursor(0, 1);

  lcd.print("Humd: ");
  lcd.print(sensor.humidity());
  lcd.printstr("%");

  delay(100);
}
