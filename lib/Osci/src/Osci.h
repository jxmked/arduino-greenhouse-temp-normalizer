#ifndef Osci_h
#define Osci_h

#include "Arduino.h"

class Osci {
  public:
    Osci(long interval);
    float value();
    bool isHighest();
    bool isLowest();
  
  private:
    long interval;

    float sineWave();

};

#endif
