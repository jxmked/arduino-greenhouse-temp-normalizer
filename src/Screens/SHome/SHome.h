#ifndef SHome_h
#define SHome_h

#include "Arduino.h"
#include "../BaseScreen.h"

#include <E_PROGRAM_STATE.h>
#include "LiquidCrystal_I2C.h"
#include "TimeInterval.h"
#include "DHTSensor.h"

class SHome : public BaseScreen
{
public:
  SHome();

  void update(unsigned long ms) override;
  void display(LiquidCrystal_I2C lcd) override;
  uint16_t refreshRate; // Sensor Refresh Rate

private:
  DHTSensor sensor;
  bool isVisible;
  TimeInterval timeInterval;
};

#endif