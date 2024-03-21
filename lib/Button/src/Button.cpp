#include "Button.h"
#include <Arduino.h>


Button::Button(uint8_t pin) : _pin(pin),
                              _pinState(0)
{
}

void Button::init()
{
  pinMode(_pin, INPUT_PULLUP);
}

bool Button::isPressed()
{
  return _pinState == PRESSED;
}

void Button::update()
{
  _pinState = digitalRead(_pin);
}