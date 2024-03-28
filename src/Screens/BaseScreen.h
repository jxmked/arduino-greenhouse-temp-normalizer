#ifndef BaseScreen_h
#define BaseScreen_h


#include "Arduino.h"

#include "LiquidCrystal_I2C.h"
#include <E_PROGRAM_STATE.h>


class BaseScreen {
public:
  BaseScreen(E_PROGRAM_STATE targetState, unsigned long scrIval);
  ~BaseScreen(void);
  E_PROGRAM_STATE targetState;
  unsigned long screenInterval;
  unsigned long initialMs;

  void begin(unsigned long initialMillis);
  virtual void update(unsigned long ms);
  virtual void display(LiquidCrystal_I2C lcd);
  virtual bool isEndOfInterval(unsigned long ms);

};


#endif