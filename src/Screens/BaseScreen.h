#ifndef BaseScreen_h
#define BaseScreen_h


#include "Arduino.h"

#include "LiquidCrystal_I2C.h"
#include <E_PROGRAM_STATE.h>


class BaseScreen {
  public:
    BaseScreen(E_PROGRAM_STATE targetState, LiquidCrystal_I2C LCD);
    E_PROGRAM_STATE targetState;
    LiquidCrystal_I2C LCD;
    
    virtual void update(void);
    virtual void display(void);
};


#endif