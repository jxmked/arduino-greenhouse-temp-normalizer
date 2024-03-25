#ifndef TimeInterval_h
#define TimeInterval_h

#include "Arduino.h"

class TimeInterval
{
public:
  TimeInterval(unsigned long interval, bool autoUpdate = false);
  void update();
  bool marked(unsigned long holdMillis=0);
  void reset();

private:
  unsigned long interval;
  bool autoUpdate;
  unsigned long lastTime;
  unsigned long time;
};

#endif
