#ifndef BrightnessAuto_h
#define BrightnessAuto_h

#include "E_SCREEN_META.h"
#include "Arduino.h"

class BrightnessAuto {
public:
  BrightnessAuto();
  /**
   * Outside values
  */
  float temp;
  float humd;
  int threshold;
  int targetBright;
  E_SCREEN_META meta;

  // We can get brightness here directly
  int brightness; // 0 - 100
  int nearBright; // ±1 degree celsius to trigger

  void begin(unsigned long ms);

  void update(unsigned long ms);

  const float DURATION = 4000.0; // ms

  private:
    unsigned long lastms;
    float _lastValue;
    bool isNearThreshold(float temp);
    void transistionBrightness(unsigned long ms);
};

#endif
