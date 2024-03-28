#ifndef SBoot_h
#define SBoot_h

#include "Arduino.h"
#include "../BaseScreen.h"
#include <E_PROGRAM_STATE.h>
#include "LiquidCrystal_I2C.h"
#include "TimeInterval.h"

// const String BOOT_TEXT = "LOADING";
// const unsigned long BOOT_INTERVAL = 3000; // 3 sec
// TimeInterval BOOT_BLINK(800, true);



class SBoot : public BaseScreen
{
public:
  SBoot();
   
  void begin(unsigned long initialMillis) override;
  void update(unsigned long ms) override;
  void display(LiquidCrystal_I2C lcd) override;
  bool isEndOfInterval(void) override;

  private:
  String BOOT_TXT;
  unsigned long BLINK_INTERVAL;
  TimeInterval BLINK_PROG;
  bool isVisible;
  unsigned long initialMs;
};



#endif