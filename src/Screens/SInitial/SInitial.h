#ifndef SInitial_h
#define SInitial_h


#include "Arduino.h"
#include "../BaseScreen.h"

#include <E_PROGRAM_STATE.h>
#include "LiquidCrystal_I2C.h"
#include "TimeInterval.h"

class SInitial : public BaseScreen
{
public:
  SInitial();
   
  void update(unsigned long ms) override;
  void display(LiquidCrystal_I2C lcd) override;

  private:
  String TXT_A;
  String TXT_B;

  bool isVisible;
};



#endif