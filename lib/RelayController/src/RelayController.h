#ifndef RelayController_h
#define RelayController_h

#include "Arduino.h"

enum class RelayControllerMode {
  TEST,
  ACTIVE,
  INACTIVE
};

class RelayController {
public:
  RelayController(uint8_t pin);
  void begin(void);
  void update(unsigned long ms);
  void run_test(unsigned long interval);
  void activate(void);
  void deactivate(void);
  RelayControllerMode getMode(void);
  void setTestMs(unsigned long ms);

  const uint8_t ACTIVE = LOW;
  const uint8_t INACTIVE = HIGH;

private:
  uint8_t pin;
  RelayControllerMode mode;
  unsigned long testInterval;
  unsigned long testMs;
};

#endif