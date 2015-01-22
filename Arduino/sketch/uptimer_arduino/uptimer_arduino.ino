/*
 * Copyright (C) 2015 Takagi Katsuyuki
 *
 * Licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 */

#include <Arduino.h>
#include <Metro.h>
#include <Wire.h>
#include <LiquidCrystal_I2C_ST7032.h>

#include "Alarm.h"
#include "CountUpTimer.h"
#include "Display.h"
#include "Keypad.h"

// pin definition
// two pins are reserved for I2C of LCD
// Uno: A4(SDA) and A5(SCL)
// Leonardo: 2(SDA) and 3(SCL)
#define DPIN_KEYPAD_START 7
#define DPIN_KEYPAD_RESET 8
#define DPIN_KEYPAD_UP_S 9
#define DPIN_KEYPAD_DOWN_S 10
#define DPIN_KEYPAD_UP_M 11
#define DPIN_KEYPAD_DOWN_M 12
#define DPIN_ALARM 13 // LED on Arduino

Alarm alarm(DPIN_ALARM);

CountUpTimer timer;

Display display;

Keypad keypad(DPIN_KEYPAD_START, DPIN_KEYPAD_RESET, DPIN_KEYPAD_UP_S, DPIN_KEYPAD_DOWN_S, DPIN_KEYPAD_UP_M, DPIN_KEYPAD_DOWN_M);

void setup() {
  display.setup();
  keypad.setup();

  displayTimerCount();
  changeAlarmTime(0);
}

void displayTimerCount() {
  display.printTimer(timer.getCount());
}

void changeAlarmTime(int diff) {
  timer.changeAlarm(diff);
  display.printAlarm(timer.getAlarmTime());
}

void loop() {
  timer.loop();
  if (timer.isWarning()) {
    alarm.start(NOTE_C3, 333, 3);
  }
  else {
    if (timer.expired()) {
      alarm.start(NOTE_C7, 100, 5);
    }
    else {
      alarm.stop();
    }
  }
  alarm.loop();

  keypad.updateKey();
  byte key = keypad.getPushed();
  switch (key) {
    case Keypad::RESET:
    {
      timer.reset();
      changeAlarmTime(0);
      break;
    }
    case Keypad::START:
    {
      timer.startStop();
      break;
    }
    case Keypad::UP_S:
    {
      changeAlarmTime(+10);
      break;
    }
    case Keypad::DOWN_S:
    {
      changeAlarmTime(-10);
      break;
    }
    case Keypad::UP_M:
    {
      changeAlarmTime(+60);
      break;
    }
    case Keypad::DOWN_M:
    {
      changeAlarmTime(-60);
      break;
    }
    case Keypad::NONE:
    {
      break;
    }
  }

  displayTimerCount();
}
