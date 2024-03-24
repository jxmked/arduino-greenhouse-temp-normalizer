#ifndef Osci_h
#define Osci_h

#include "Arduino.h"

class Osci
{
public:
  Osci(long interval);
  float value();
  bool isHigh();
  bool isLow();

private:
  long interval;

  float sineWave();
};

#endif
