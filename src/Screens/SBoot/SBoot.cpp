#include "SBoot.h"
#include <Arduino.h>
#include <E_PROGRAM_STATE.h>
#include <LiquidCrystal_I2C.h>
#include "../BaseScreen.h"
#include "TimeInterval.h"

#define __BOOT_TEXT "LOADING"
#define __BOOT_INTERVAL 3000      // 3 sec
#define __BOOT_BLINK_INTERVAL 800 // 800 ms

SBoot::SBoot(LiquidCrystal_I2C LCD) : BaseScreen(BOOT, LCD) : BOOT_TXT(__BOOT_TEXT),
                                                              BLINK_INTERVAL(__BOOT_INTERVAL),
                                                              BLINK_PROG(800, true)
{
}

void SBoot::update()
{
}

void SBoot::display()
{
}