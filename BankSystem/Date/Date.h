//
// Created by Rolan Abbasguliev on 23.02.2021.
//

#ifndef BANKSYSTEM_DATE_H
#define BANKSYSTEM_DATE_H

#include "../Exception/Exception.h"
#include <ctime>
class Date
{
public:
  int Day, Month, Year;

  Date () {}

  Date(int day, int month, int year)
  {
    if (year < 2020)
      throw ExeptionHandler("Error year");
    if (month > 12 || month < 1)
      throw ExeptionHandler("Error month");
    else
    {
      if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
      {
        if (day > 31 || day < 1)
          throw ExeptionHandler("Error day in odd month");
      }
      else if (month == 4 || month == 6 || month == 9 || month == 11)
      {
        if (day > 30 || day < 1)
          throw ExeptionHandler("Error day in even moth");
      }
      else if (month == 2 && (year % 4 == 0))
      {
        if (day > 29 || day < 1)
          throw ExeptionHandler("Error day leap year");//throw new DateException("В " + month.ToString() + " месяц не может быть " + day.ToString() + "дней(Високосный год)");
      }
      else
      {
        if (day > 28 || day < 1)
          throw ExeptionHandler("Error day leap year");
      }
    }
    Day = day;
    Month = month;
    Year = year;
  }


  friend Date operator++(Date date)
  {
    int maxDays = date.MaxDaysInMonth();
    if (date.Day == maxDays)
    {
      date.Day = 1;
      date.Month += 1;
      if (date.Month >= 13)
      {
        date.Year += 1;
        date.Month = 1;
        return date;
      }
      else
        return date;
    }
    else
    {
      date.Day++;
      return date;
    }
  }

  friend bool operator>=(Date dateL, Date dateR)
  {
    return !(dateL < dateR);
  }


  //wrong
  int InDays()
  {
    return Day + Year * 365 + Month * 30;
  }


  friend bool operator<=(Date dateL, Date dateR)
  {
    return !(dateL > dateR);
  }

  friend bool operator>(Date dateL, Date dateR)
  {
    if (dateL.Year > dateR.Year)
      return true;
    else if (dateL.Year < dateR.Year)
      return false;
    else
    {
      if (dateL.Month > dateR.Month)
        return true;
      else if (dateL.Month < dateR.Month)
        return false;
      else
      {
        if (dateL.Day > dateR.Day)
          return true;
        else if (dateL.Day < dateR.Day)
          return false;
        else
          return false;
      }
    }
  }

  friend bool operator==(Date dateL, Date dateR)
  {
    if (dateL.Year == dateR.Year && dateL.Month == dateR.Month && dateR.Day == dateL.Day)
      return true;
    return false;
  }

  friend bool operator<(Date dateL, Date dateR)
  {
    if (dateL.Year < dateR.Year)
      return true;
    else if (dateL.Year > dateR.Year)
      return false;
    else
    {
      if (dateL.Month < dateR.Month)
        return true;
      else if (dateL.Month > dateR.Month)
        return false;
      else
      {
        if (dateL.Day < dateR.Day)
          return true;
        else if (dateL.Day > dateR.Day)
          return false;
        else
          return false;
      }
    }
  }



  int MaxDaysInMonth()
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

  void SetDay(int day)
  {
    this->Day = day;
  }

  void SetMonth(int month)
  {
    this->Month = month;
  }

  void SetYear(int year)
  {
    this->Year = year;
  }
};

#endif //BANKSYSTEM_DATE_H
