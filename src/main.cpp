#include <Arduino.h>
#include "Program.h"
#include "Button.h"
#include "Helpers.h"
#include "PIN_DATA.h"

const uint8_t PLUS = PIN_DATA.PLUS_BTN;
const uint8_t MINUS = PIN_DATA.MINUS_BTN;

Program app;
unsigned long enterIval = 0;

Button enter(PIN_DATA.ENTER_BTN);

int curStateClick;
int lastStateClick;

void setup() {

  pinMode(PIN_DATA.PLUS_BTN, INPUT_PULLUP);
  pinMode(PIN_DATA.MINUS_BTN, INPUT_PULLUP);

  app.begin();

  lastStateClick = digitalRead(PIN_DATA.MINUS_BTN);
}

void loop() {
  const auto PLUS = digitalRead(PIN_DATA.PLUS_BTN);
  const auto MINUS = digitalRead(PIN_DATA.MINUS_BTN);

  curStateClick = MINUS;

  if (curStateClick != lastStateClick && curStateClick == 1) {
    if (PLUS != curStateClick) {
      app.pressIncrease();
    } else {
      app.pressDecrease();
    }
  }

  lastStateClick = curStateClick;

  if (enter.read() == Button::PRESSED) {
    if (isDiffAchieved(millis(), enterIval, 5000)) {
      app.configMode();
    }
  } else {
    enterIval = millis();
  }

  if (enter.pressed()) {
    app.pressEnter();
  }

  app.update();
  app.display();
}