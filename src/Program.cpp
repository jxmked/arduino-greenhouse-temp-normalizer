#include "Program.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "TimeInterval.h"
#include "Helpers.h"
#include "LCD_META.h"
#include "DHTSensor.h"
#include "PIN_DATA.h"
#include "RelayController.h"
#include "TemperatureController.h"
#include "CONFIG_T.h"
#include "E_SCREEN_META.h"
#include "BrightnessAuto.h"

// Will include all screen files
#include "Screens/index.cpp"

/** OUR DATA & CONFIG **/

CONFIG_T CONFIG;

int THRESHOLD = 31;


/** END DATA & CONFIG **/
/**
 * Screen Object
*/
LiquidCrystal_I2C lcd(LCD_META.addr, LCD_META.rows, LCD_META.cols);
TimeInterval lcd_hz(200, 0, true); // LCD Refresh Rate - 0.2 sec
BrightnessAuto brightAuto;

/*** END SCREEN ***/

/**
 * DHT Sensor
*/
DHTSensor mainSensor = DHTSensor(PIN_DATA.DHT_Sensor);
TimeInterval mainSensorHz = TimeInterval(2000, 0, true);

/** END DHT SENSOR */

/**
 * Relay Controller and Logic
*/
RelayController recon = RelayController(PIN_DATA.Fan_Relay);
TemperatureController tempCont = TemperatureController();
/** END RELAY CONTROLLER AND LOGIC */

/**
 * Screens
 */
SShow_Thres* __showthres__ = new SShow_Thres();
SHome* __shome__ = new SHome();

BaseScreen* screens[] = {
    __showthres__,
    new SBoot(),
    new SInitial(),
     __shome__ };

const int screenLength = sizeof(screens) / sizeof(screens[0]);

/** END SCREENS */

unsigned long _lastTime = 0;
E_PROGRAM_STATE _timeOwner = E_PROGRAM_STATE::PRESET;
E_PROGRAM_STATE _lastTimeOwner = E_PROGRAM_STATE::PRESET;

// calling every screen as first boot since the currentFirst has been change
bool firstCalled = true;
E_PROGRAM_STATE currentFirst = E_PROGRAM_STATE::BOOT;

// Deny all button actions during boot...
bool isReady = false;

Program::Program() : state(E_PROGRAM_STATE::BOOT),
currentInterval(0) { }

void Program::begin() {
  const auto initialMillis = millis();

  /** Lets populate config with initial data **/
  CONFIG.THRESHOLD = 32;
  CONFIG.isSystmActive = true;
  CONFIG.SCREEN_META = E_SCREEN_META::AUTO;

  /** END POPULATE DATA **/




  lcd.begin(LCD_META.rows, LCD_META.cols);
  lcd.backlight();
  brightAuto.begin(initialMillis);

  __showthres__->threshold = THRESHOLD;

  recon.begin();
  tempCont.begin();


  for (int index = 0; index < screenLength; index++) {
    BaseScreen& scr = *screens[index];

    scr.begin(initialMillis);
  }
}

void Program::show_threshold(unsigned long ms) {
  state = E_PROGRAM_STATE::SHOW_THRESHOLD;
  _lastTime = ms;
}

void Program::pressEnter() {
  if (!isReady) return;

  show_threshold(millis());
}

void Program::pressDecrease() {
  if (!isReady) return;

  show_threshold(millis());

  brightAuto.targetBright = 0;

  THRESHOLD--;
}

void Program::pressIncrease() {
  if (!isReady) return;
  show_threshold(millis());

  brightAuto.targetBright = 100;

  THRESHOLD++;
}


/********** UPDATE ***********/

void Program::update() {
  const auto ms = millis();

  // Always Update Our Sensor Even in the Background
  if (mainSensorHz.marked())
    mainSensor.update();

  /** Populate screens with datas */
  __shome__->updateReadings(mainSensor.temperature(), mainSensor.humidity());
  __showthres__->threshold = THRESHOLD;

  brightAuto.temp = mainSensor.temperature();
  brightAuto.humd = mainSensor.humidity();
  brightAuto.threshold = THRESHOLD;

  /** End Populate screens with datas */

  tempCont.setThreshold(THRESHOLD);
  tempCont.setTempHumd(mainSensor.temperature(), mainSensor.humidity());
  tempCont.update(ms);

  brightAuto.update(ms);

  analogWrite(PIN_DATA.LCD_BLIGHT, map(brightAuto.brightness, 0, 100, 10, 156));

  if (isReady && tempCont.isThresholdExceed()) {
    recon.activate();
  } else {
    recon.deactivate();
  }

  for (int index = 0; index < screenLength; index++) {
    BaseScreen& scr = *screens[index];

    if (scr.targetState != state)
      continue;

    scr.update(ms);
    break;
  }

  // Update time interval
  // and time owner
  _timeOwner = state;

  if (_timeOwner != _lastTimeOwner) {
    _lastTimeOwner = _timeOwner;
    _lastTime = millis();
  }
  /////////////////////////////

  switch (state) {
  case E_PROGRAM_STATE::BOOT:
    if (isDiffAchieved(millis(), _lastTime, screens[1]->screenInterval)) {
      state = E_PROGRAM_STATE::INITIAL;
    }

    break;

  case E_PROGRAM_STATE::INITIAL:
    if (isDiffAchieved(millis(), _lastTime, screens[2]->screenInterval)) {
      state = E_PROGRAM_STATE::SHOW_THRESHOLD;
    }

    break;

  case E_PROGRAM_STATE::HOME:
    isReady = true;

    break;

  case E_PROGRAM_STATE::SHOW_THRESHOLD:
    if (isDiffAchieved(millis(), _lastTime, screens[0]->screenInterval)) {
      state = E_PROGRAM_STATE::HOME;
    }

    break;

  default:
    break;
  }

  recon.update(ms);
}\


/************** END UPDATE ***************/


/************** DISPLAY ******************/

void Program::display() {
  if (!lcd_hz.marked())
    return;
  for (int index = 0; index < screenLength; index++) {
    BaseScreen& scr = *screens[index];

    if (scr.targetState != state)
      continue;

    scr.display(lcd);
    break;
  }
}


/************ END DISPLAY ****************/


E_PROGRAM_STATE Program::getState() {
  return state;
}

void Program::configMode() {

}