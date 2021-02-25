#ifndef BANKSYSTEM_TIME_H
#define BANKSYSTEM_TIME_H

#include "../Exception/Exception.h"
#include <ctime>
#include <iostream>
using namespace std;

class Time
{
private:
  int Day = 0, Month = 0, Year = 0;
  int Hour = 0, Min = 0, Sec = 0;
public:
  Time();

  int getDay();
  int getMonth();
  int getYear();
  int getHour();
  int getMin();
  int getSec();


  int MaxDaysInMonth();

  bool endMonth();
  void SetDate(int Day, int Month, int Year);
  bool operator==(const Time &f);
  Time& operator=(const Time &f);
  bool operator<(const Time &f);
  bool operator<=(const Time &f);
  bool operator>(const Time &f);
  bool operator>=(const Time &f);
  //ostream& operator<<(ostream &out);

  void DayPlus();
  void showTime();
};

#endif //BANKSYSTEM_TIME_H
