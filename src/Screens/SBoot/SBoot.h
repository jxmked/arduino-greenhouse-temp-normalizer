#ifndef SBoot_h
#define SBoot_h

#include "Arduino.h"
#include "../BaseScreen.h"

#include "LiquidCrystal_I2C.h"
#include "TimeInterval.h"

class SBoot : public BaseScreen {
public:
  SBoot();

  void update(unsigned long ms) override;
  void display(LiquidCrystal_I2C lcd) override;

private:
  String BOOT_TXT;
  TimeInterval BLINK_PROG;
  bool isVisible;

  // Just for fun
  int loading_value;
};



#endif