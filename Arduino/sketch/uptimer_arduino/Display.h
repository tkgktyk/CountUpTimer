
#ifndef Display_h_
#define Display_h_

#define ROW_TIMER 0
#define ROW_ALARM 1

class Display {
private:
  LiquidCrystal_I2C_ST7032 _lcd;
  int _time[2];

public:
  Display() :
  _lcd(32, true) // contrast, 5V
  {
    memset(_time,0,sizeof(_time));
  }

  void setup() {
    _lcd.begin(8, 2);  
    _lcd.setCursor(0, ROW_TIMER);
    _lcd.print("T  00:00");
    _lcd.setCursor(0, ROW_ALARM);
    _lcd.print("A  00:00");
  }

private:
  void printTime(int time, byte row) {
    if (_time[row] == time) { 
      return;
    }
    _time[row] = time;
    //_lcd.setCursor(11, row);
    //sprintf(time_buffer, "%02d:%02d", time / 60, time % 60);
    //_lcd.print(time_buffer);

    // 1s
    _lcd.setCursor(7, row);
    int tmp = time % 10;
    _lcd.print(tmp);
    // 10s
    _lcd.setCursor(6, row);
    time = (time - tmp) / 10;
    tmp = time % 6;
    _lcd.print(tmp);
    // 1m
    _lcd.setCursor(4, row);
    time = (time - tmp) / 6;
    tmp = time % 10;
    _lcd.print(tmp);
    // 10m
    _lcd.setCursor(3, row);
    time = (time - tmp) / 10;
    tmp = time % 10;
    _lcd.print(tmp);
  }

public:
  void printTimer(int time) {
    printTime(time, ROW_TIMER);
  }

  void printAlarm(int time) {
    printTime(time, ROW_ALARM);
  }
};

#endif








