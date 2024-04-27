#ifndef CONFIRMDIAG_h
#define CONFIRMDIAG_h


#include <LiquidCrystal_I2C.h>

class ConfirmDiag {

public:
  ConfirmDiag();
  void update(unsigned long ms);
  void display(LiquidCrystal_I2C lcd);
  bool getResult();
  void btnIncrease();
  void btnDecrease();


};






#endif
