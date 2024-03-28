#ifndef Program_h
#define Program_h

#include "Arduino.h"
#include <E_PROGRAM_STATE.h>

class Program
{
public:
  Program();
  void begin();
  void show_threshold(unsigned long inMs);
  void pressEnter();
  void pressDecrease();
  void pressIncrease();
  void update();
  void display();
  E_PROGRAM_STATE getState();

private:
  E_PROGRAM_STATE state;
  unsigned long currentInterval;
  unsigned long getMillis();
  unsigned long getDiffMillis(unsigned long fromMs);
};

#endif
