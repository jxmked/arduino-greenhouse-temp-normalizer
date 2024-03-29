#ifndef SConfig_h
#define SConfig_h

#include "Arduino.h"
#include "../BaseScreen.h"

#include "LiquidCrystal_I2C.h"

class SConfig : public BaseScreen {
public:
  SConfig();

  void update(unsigned long ms) override;
  void display(LiquidCrystal_I2C lcd) override;
  void updateReadings(float temp, float humd);
  void increment();
  void decrease();
  void enter();
  

private:
  bool isVisible;
  float temperature;
  float humidity;
};

#endif