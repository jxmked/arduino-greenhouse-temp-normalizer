#ifndef BrightnessAuto_h
#define BrightnessAuto_h

#include "E_SCREEN_META.h"
#include "Arduino.h"

class BrightnessAuto {
public:
  BrightnessAuto();
  float temp;
  float humd;
  int threshold;
  int brightness; // 0 - 100
  E_SCREEN_META meta;
  int nearBright; // ±1 degree celsius to trigger
  void update(unsigned long ms);

  const int TRANSITION_INTERVAL = 1500; // 1.5 sec

  private:
    unsigned long lastIntervalA;
    bool onAnimate;
    bool onIncrease;


};

#endif
