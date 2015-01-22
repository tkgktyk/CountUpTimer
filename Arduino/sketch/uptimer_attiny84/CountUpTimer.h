/*
* Copyright (C) 2015 Takagi Katsuyuki
*
* Licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
*/

#ifndef CountUpTimer_h_
#define CountUpTimer_h_

#define GAP_FOR_WARNING 60

class CountUpTimer {
private:
  static const int MAX_COUNT = 99 * 60 + 59;
  static const int MAX_ALARM_TIME = 90 * 60 + 0;
private:
  Metro _metro;
  int _count;
  boolean _isCounting;
  boolean _expired;
  boolean _isWarning;
  int _alarmTime;

public:
  CountUpTimer() :
  _metro(1000) {
    reset();
  }

  void reset() {
    if (_count == 0) {
      _alarmTime = 0;
    }
    _metro.reset();
    _count = 0;
    _isCounting = false;
  }

  int getCount() {
    return _count;
  }

  void loop() {
    if (_isCounting && (_metro.check() == 1)) {
      _count = constrain(_count + 1, 0, MAX_COUNT);
      if (_count == _alarmTime) {
        _expired = true;
        _isWarning = false;
      }
      else if (_count < _alarmTime) {
        _expired = false;
        _isWarning = false;
      }
      else if ((_count - _alarmTime) >= GAP_FOR_WARNING) {
        _isWarning = true;
      }
    }
  }

  void startStop() {
    if (_isCounting) {
      // stop
      // if time isn't up yet, stop counting. Otherwise, stop alarm only.
      if (_expired) {
        _expired = false;
      }
      else {
        _isCounting = false;
        _isWarning = false;
      }
    }
    else {
      // start
      _metro.reset();
      _isCounting = true;
    }
  }

  int getAlarmTime() {
    return _alarmTime;
  }

  void changeAlarm(int diff) {
    _alarmTime = constrain(_alarmTime + diff, 0, MAX_ALARM_TIME);
    _expired = false;
    _isWarning = false;
  }

  boolean expired() {
    return _expired;
  }

  boolean isWarning() {
    return _isWarning;
  }
};

#endif
