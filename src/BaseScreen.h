#ifndef BaseScreen_h
#define BaseScreen_h


#include "Arduino.h"

#include "LiquidCrystal_I2C.h"
#include <E_PROGRAM_STATE.h>


class BaseScreen {
  public:
    BaseScreen(LiquidCrystal_I2C LCD, E_PROGRAM_STATE objectTargetState);
    LiquidCrystal_I2C LCD;
    E_PROGRAM_STATE targetState;
    
    virtual void update(void);
    virtual void display(void);
};


#endif