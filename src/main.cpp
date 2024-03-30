#include <Arduino.h>
#include "Program.h"
#include "Button.h"
#include "Helpers.h"
#include "PIN_DATA.h"

Button plus(PIN_DATA.PLUS_BTN);
Button minus(PIN_DATA.MINUS_BTN);
Button enter(PIN_DATA.ENTER_BTN);

Program app;

unsigned long enterIval = 0;

void setup() {
  app.begin();

  plus.begin();
  plus.set_repeat(500, 200);

  minus.begin();
  minus.set_repeat(500, 200);

  enter.begin();
  enter.set_repeat(5000, 10000);
}

void loop() {

  if(enter.read() == Button::PRESSED) {
    if(isDiffAchieved(millis(), enterIval, 5000)) {
      app.configMode();
    }
  } else {
    enterIval = millis();
  }

  if (enter.pressed()) {
    app.pressEnter();
  }

  if(minus.pressed()) {
    app.pressDecrease();
  }

  if(plus.pressed()) {
    app.pressIncrease();
  }

  app.update();
  app.display();
}