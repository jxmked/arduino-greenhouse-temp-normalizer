#ifndef SShow_Thres_h
#define SShow_Thres_h

#include "Arduino.h"
#include "../BaseScreen.h"
#include "LiquidCrystal_I2C.h"

class SShow_Thres : public BaseScreen
{
public:
  SShow_Thres();
  unsigned long threshold;

  void update(unsigned long ms) override;
  void display(LiquidCrystal_I2C lcd) override;

private:
  bool isVisible;
  String txt;
};

#endif