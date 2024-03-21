#include "Button.h"
#include <Arduino.h>


Button::Button(uint8_t pin) : pin(pin),
                              _pinState(0)
{
}

void Button::init()
{
  pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed()
{
  return _pinState == PRESSED;
}

void Button::update()
{
  _pinState = digitalRead(pin);
}