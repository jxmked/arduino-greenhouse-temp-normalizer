#include <Arduino.h>
#include "DEFINITION.h"
// #include "Program.h"
#include "Button.h"
#include "Helpers.h"
#include "PIN_DATA.h"


#include "TimeInterval.h"
#include <LiquidCrystal_I2C.h>

const uint8_t PLUS = PIN_DATA.PLUS_BTN;
const uint8_t MINUS = PIN_DATA.MINUS_BTN;

// Program app;
unsigned long enterIval = 0;

Button enter(PIN_DATA.ENTER_BTN);

int curStateClick;
int lastStateClick;

LiquidCrystal_I2C scr(0x27, 16,2);

int pos = 0;
TimeInterval hz(100, 0, true);

byte arrow_up[8] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100
};

void setup() {

  scr.begin(16,2);
  scr.createChar(1, arrow_up);
  scr.backlight();

  scr.setCursor(0,0);
  scr.print("Confirm   Cancel");


  pinMode(PIN_DATA.PLUS_BTN, INPUT_PULLUP);
  pinMode(PIN_DATA.MINUS_BTN, INPUT_PULLUP);

  analogWrite(PIN_DATA.LCD_BLIGHT, 1024);
  digitalWrite(PIN_DATA.Fan_Relay, HIGH);
  
  // app.begin();

  lastStateClick = digitalRead(PIN_DATA.MINUS_BTN);

  delay(10); // Just making other parts to be ready
}

void loop() {
  const auto PLUS = digitalRead(PIN_DATA.PLUS_BTN);
  const auto MINUS = digitalRead(PIN_DATA.MINUS_BTN);

  curStateClick = MINUS;

  if (curStateClick != lastStateClick && curStateClick == 1) {
    if (PLUS != curStateClick) {
      pos++;
      // app.pressIncrease();
    } else {
      pos--;
      // app.pressDecrease();
    }
  }

  lastStateClick = curStateClick;

  if (enter.read() == Button::PRESSED) {
    if (isDiffAchieved(millis(), enterIval, 5000)) {
      // app.configMode();
    }
  } else {
    enterIval = millis();
  }

  if (enter.pressed()) {
    // app.pressEnter();
  }

  // app.update();
  // app.display();

  pos = min(max(pos, 0), 16);
  

  if(hz.marked()) {
  // scr.clear();
  // scr.setCursor(pos, 0);
  // scr.write(byte(1));
}


  //delay(100);
}