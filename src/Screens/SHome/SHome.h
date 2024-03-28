#ifndef SHome_h
#define SHome_h

#include "Arduino.h"
#include "../BaseScreen.h"

#include "LiquidCrystal_I2C.h"

class SHome : public BaseScreen {
public:
  SHome();

  void update(unsigned long ms) override;
  void display(LiquidCrystal_I2C lcd) override;
  void updateReadings(float temp, float humd);

private:
  bool isVisible;
  float temperature;
  float humidity;
};

#endif