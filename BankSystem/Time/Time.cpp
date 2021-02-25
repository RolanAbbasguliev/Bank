#include "Time.h"

Time::Time()
{
  time_t t = time(nullptr);

  tm* now = localtime(&t);

  this->Year = now->tm_year + 1900;
  this->Month = now->tm_mon + 1;
  this->Day = now->tm_mday;

  this->Hour = now->tm_hour;
  this->Min = now->tm_min;
  this->Sec = now->tm_sec;
}

int Time::getDay()
{
  return this->Day;
}
int Time::getMonth()
{
  return this->Month;
}
int Time::getYear()
{
  return this->Year;
}
int Time::getHour()
{
  return this->Hour;
}
int Time::getMin()
{
  return this->Min;
}
int Time::getSec()
{
  return this->Sec;
}

void Time::SetDate(int Day, int Month, int Year)
{
  if (Year < 2020)
    throw ExeptionHandler("Error year");
  if (Month > 12 || Month < 1)
    throw ExeptionHandler("Error month");
  else
  {
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    {
      if (Day > 31 || Day < 1)
        throw ExeptionHandler("Error day in odd month");
    }
    else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
    {
      if (Day > 30 || Day < 1)
        throw ExeptionHandler("Error day in even moth");
    }
    else if (Month == 2 && (Year % 4 == 0))
    {
      if (Day > 29 || Day < 1)
        throw ExeptionHandler("Error day leap year");//throw new DateException("В " + month.ToString() + " месяц не может быть " + day.ToString() + "дней(Високосный год)");
    }
    else if (Month == 2 && (Year % 4 == 0))
    {
      if (Day > 28 || Day < 1)
        throw ExeptionHandler("Error day leap year");
    }
  }
  this->Day = Day;
  this->Month = Month;
  this->Year = Year;
}


int Time::MaxDaysInMonth()
{
  if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    return 31;
  else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
    return 30;
  else if (Month == 2 && (Year % 4 == 0))
    return 29;
  else
    return 28;
}


bool Time::operator==(const Time &f)
{
  if (f.Year == this->Year && f.Month == this->Month && f.Day == this->Day &&
          f.Hour == this->Hour && f.Min== this->Min && f.Sec == this->Sec)
    return true;
  return false;
}

Time &Time::operator=(const Time &f)
{
  this->Year = f.Year;
  this->Month = f.Month;
  this->Day = f.Day;

  this->Hour = f.Hour;
  this->Min = f.Min;
  this->Sec = f.Sec;

  return *this;
}


bool Time::operator<(const Time &f)
{
  if (this->Year < f.Year)
    return true;
  else if (this->Year > f.Year)
    return false;
  else
  {
    if (this->Month < f.Month)
      return true;
    else if (this->Month > f.Month)
      return false;
    else
    {
      if (this->Day < f.Day)
        return true;
      else if (this->Day > f.Day)
        return false;
    }
  }
  return true;
}

bool Time::operator>(const Time &f)
{
  if (*this < f)
    return false;
  return true;
}

bool Time::operator<=(const Time &f)
{
  if (*this < f || *this == f)
    return true;
  else
    return false;
}

bool Time::operator>=(const Time &f)
{
  if (*this > f || *this == f)
    return true;
  return false;
}

/*
ostream &Time::operator<<(ostream &out)
{

  out << "DATE: " << this->Year << "-" << this->Month << "-" << this->Day << "\n";
  out << "TIME: " << this->Hour <<":" << this->Min << ":" << this->Sec << "\n";
  return out;
}
*/


void Time::DayPlus()
{
  int maxDay = this->MaxDaysInMonth();
  if (this->Day == maxDay)
  {
    this->Day = 1;
    this->Month += 1;
    if (this->Month > 12)
    {
      this->Month = 1;
      this->Year += 1;
    }
  }
  else
    this->Day++;
}

void Time::showTime()
{
  cout << "DATE: " << this->Year << "-" << this->Month << "-" << this->Day << "\n";
  cout << "TIME: " << this->Hour <<":" << this->Min << ":" << this->Sec << "\n";
}

bool Time::endMonth()
{
  if (this->MaxDaysInMonth() == this->Day)
    return true;
  return false;
}


