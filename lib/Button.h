#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
public:
  Button(uint8_t pin);

  void init();

  /**
   * Check if the button is pressed
   */
  bool isPressed();

  /**
   * Update button state.
   *
   * Place this inside of a loop
   */
  void update();

  const static bool PRESSED = LOW;
  const static bool RELEASED = HIGH;

private:
  int _pinState;
  uint8_t _pin;
}

#endif

;