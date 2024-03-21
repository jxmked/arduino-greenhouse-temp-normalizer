#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{

private:
  uint8_t pin;
  int _pinState;

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

};

#endif