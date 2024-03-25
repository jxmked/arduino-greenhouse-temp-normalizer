#ifndef Program_h
#define Program_h

#include "Arduino.h"

enum E_PROGRAM_STATE
{
  BOOT,
  INITIAL,
  HOME,
  SHOW_THRESHOLD,
  SET_THRESHOLD
};

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
  void showBoot();
  E_PROGRAM_STATE getStatus();

private:
  E_PROGRAM_STATE status;
  unsigned long currentInterval;
  unsigned long getMillis();
  unsigned long getDiffMillis(unsigned long fromMs);
};

#endif
