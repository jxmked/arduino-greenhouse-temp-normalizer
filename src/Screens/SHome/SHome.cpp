#include "SHome.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "../BaseScreen.h"
#include "TimeInterval.h"
#include "Helpers.h"
#include "LCD_META.h"
#include "DHTSensor.h"
#include "PIN_DATA.h"

#define __SENSOR_REFRESH_RATE 2000 // 2 sec

SHome::SHome() : BaseScreen(E_PROGRAM_STATE::HOME, 1),
refreshRate(__SENSOR_REFRESH_RATE),
sensor(DHTSensor(PIN_DATA.DHT_Sensor)),
isVisible(true),
timeInterval(TimeInterval(__SENSOR_REFRESH_RATE, 0, true)) { }

void SHome::update(unsigned long ms) {

  if (timeInterval.marked()) {
    // Update sensor data
    sensor.update();
  }
}

void SHome::display(LiquidCrystal_I2C lcd) {
  if (!isVisible)
    return;

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(sensor.temperature());
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humd:");
  lcd.print(sensor.humidity());
  lcd.print("%");
}
