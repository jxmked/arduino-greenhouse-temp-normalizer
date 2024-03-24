#include <Arduino.h>
#include "Button.h"
#include "DHTSensor.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 16);

#define P_SENSOR A0

void lcdHandler();

int counter = 0;
Button plus(2);
Button minus(4);

DHTSensor sensor(P_SENSOR);


int a =0;
int b = 0;


void foo() {
  a++;
  delay(2000);
  yield();
}

void bar() {
  b++;

  delay(1000);

  yield();
}

void printer() {
  lcd.setCursor(0,0);
  lcd.print(a);

  lcd.setCursor(0, 1);
  lcd.print(b);

  delay(100);
  yield();
}

void setup()
{
  lcd.begin(2, 16);
  lcd.backlight();

  plus.begin();
  plus.set_repeat(500, 200);

  minus.begin();
  minus.set_repeat(500, 200);

  // Scheduler.startLoop(foo);
  // Scheduler.startLoop(bar);
}

void loop()
{
  // printer();

  // foo();

  // bar();




  // return;

  sensor.update();

  if (plus.pressed())
  {
    counter++;
  }

  if (minus.pressed())
  {
    counter--;
  }

  lcdHandler();
   yield();
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
