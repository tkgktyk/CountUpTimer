/*
* Copyright (C) 2015 Takagi Katsuyuki
*
* Licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
*/

#ifndef Keypad_H_
#define Keypad_H_

class Keypad {
public:
  static const byte START = 0;
  static const byte RESET = 1;
  static const byte UP_S = 2;
  static const byte DOWN_S = 3;
  static const byte UP_M = 4;
  static const byte DOWN_M = 5;
  static const byte N = 6;
  static const byte NONE = N;
private:
  byte _dpin[N];
  byte _pressed;
  byte _pushed;

public:
  Keypad(byte start, byte reset, byte up_s, byte down_s, byte up_m, byte down_m) {
    _dpin[START] = start;
    _dpin[RESET] = reset;
    _dpin[UP_S] = up_s;
    _dpin[DOWN_S] = down_s;
    _dpin[UP_M] = up_m;
    _dpin[DOWN_M] = down_m;
    _pressed = NONE;
    _pushed = NONE;
  }

  void setup() {
    for (byte i = 0; i < N; ++i) {
      pinMode(_dpin[i], INPUT_PULLUP);
    }
  }

private:
  byte readKey() {
    byte key = NONE;
    // check key's state.
    // when some keys are pressed (LOW), choice minimum index.
    for (byte i = 0; i < N; ++i) {
      if (digitalRead(_dpin[i]) == LOW) {
        key = i;
        break;
      }
    }
    // return pressed key or NONE
    return key;
  }

  byte readPressKey() {
    byte key = readKey();
    // cancel chattering
    delay(1); // delay 1ms
    if (key != readKey()) {
      return NONE;
    }
    else {
      return key;
    }
  }

public:
  void updateKey() {
    byte RESET_key = readPressKey();
    if (RESET_key == NONE){
      _pushed = _pressed;
    }
    else {
      _pushed = NONE;
    }
    _pressed = RESET_key;
  }

  byte getPushed() {
    return _pushed;
  }
};

#endif
