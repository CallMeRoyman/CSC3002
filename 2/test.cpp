/* Q1:
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 */

#include <string>
#include <iostream>
#include "csc300222fall/assignment2/lib.h"
#include "csc300222fall/assignment2/calendar.h"

using namespace std;

Month stringToMonth(string s)
{
   if (s == "JANUARY") {
      return JANUARY;
   }
   if (s == "FEBRUARY") {
      return FEBRUARY;
   }
   if (s == "MARCH") {
      return MARCH;
   }
   if (s == "APRIL") {
      return APRIL;
   }
   if (s == "MAY") {
      return MAY;
   }
   if (s == "JUNE") {
      return JUNE;
   }
   if (s == "JULY") {
      return JULY;
   }
   if (s == "AUGUST") {
      return AUGUST;
   }
   if (s == "SEPTEMBER") {
      return SEPTEMBER;
   }
   if (s == "OCTOBER") {
      return OCTOBER;
   }
   if (s == "NOVEMBER") {
      return NOVEMBER;
   }
   if (s == "DECEMBER") {
      return DECEMBER;
   }
}

/* TODO PART:
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
string monthToString(Month month)
{
   switch (month){
   case JANUARY: return "JANUARY";
   case FEBRUARY: return "FEBRUARY";
   case MARCH: return "MARCH";
   case APRIL: return "APRIL";
   case MAY: return "MAY";
   case JUNE: return "JUNE";
   case JULY: return "JULY";
   case AUGUST: return "AUGUST";
   case SEPTEMBER: return "SEPTEMBER";
   case OCTOBER: return "OCTOBER";
   case NOVEMBER: return "NOVEMBER";
   case DECEMBER: return "DECEMBER";
   default: return "???";
   }
}

Month operator++(Month &month, int)
{
   Month old = month;
   month = Month((month + 1)%12);
   return old;
}


/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Date class.  The default
 * constructor creates a Date with a zero internal value that must
 * be assigned a new value before it is used.  The others initialize
 * the date from the arguments by calling the private initDate method.
 */

Date::Date()
{
   initDate(1, JANUARY, 1900);
}

Date::Date(int day, Month month, int year)
{
   initDate(day, month, year);
}

Date::Date(Month month, int day, int year)
{
   initDate(day, month, year);
}

/*
 * TODO function
 * Implementation notes: getDay, getMonth
 * --------------------------------------
 * In this implementation of the Date class, the day and the month are
 * not stored explicitly but must instead be computed from the dayInYear
 * field.
 */

int Date::getDay()
{
   return dayInYear;
   /*
   int dd = 0;
   Month mm = JANUARY;
   while (dayInYear > dd)
   {
      mm++;
      dd += daysInMonth(month, year);
   }
   return (dayInYear - dd);
   */

}

/*
 * TODO function
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

Month Date::getMonth()
{
   return month;
   /*
   int dd = 0;
   Month mm = JANUARY;
   while (dayInYear > dd){
      mm++;
      dd += daysInMonth(month, year);
   }
   return mm;
   */
}

int Date::getYear()
{
   return year;
}

/*
 * TODO function
 * Implementation notes: toString
 * ------------------------------
 * The toString method uses the getters to perform the translation into
 * day/month/year values.
 */

string Date::toString()
{
   string dd = to_string(getDay());
   string mmm = capitalize(monthToString(getMonth()));
   string yyyy = to_string(getYear());
   return dd + "-" + mmm + "+" + yyyy;
}

string Date::capitalize(string str)
{
   string Str = "";
   Str += toupper(str[0]);
   if (str.length() > 1) Str += toLowerCase(str.substr(1, str.length()));
   return Str;
}

void Date::initDate(int day, Month month, int yyyy)
{
   day = day;
   month = month;
   year = yyyy;
}

Date operator+(Date date, int delta)
{
   Date newDay;
   newDay.dayInYear = date.dayInYear + delta;
   return newDay;
}

Date operator-(Date date, int delta)
{
   return date - delta;
}

int operator-(Date d1, Date d2)
{
   return d1.dayInYear - d2.dayInYear;
}

Date &operator+=(Date &date, int delta)
{
   return date = date + delta;
}

Date &operator-=(Date &date, int delta)
{
   return date = date - delta;
}

Date operator++(Date &date)
{
   return date = date + 1;
}

Date operator++(Date &date, int)
{
   Date old = date;
   date = date + 1;
   return old;
}

Date operator--(Date &date)
{
   return date = date - 1;
}

Date operator--(Date &date, int)
{
   Date old = date;
   date = date - 1;
   return old;
}

bool operator==(Date d1, Date d2)
{
   return d1 == d2;
}

bool operator!=(Date d1, Date d2)
{
   return !(d1 == d2);
}

bool operator<(Date d1, Date d2)
{
   return d1 < d2;
}

bool operator<=(Date d1, Date d2)
{
   return d1 <= d2;
}

bool operator>(Date d1, Date d2)
{
   return d1 > d2;
}

bool operator>=(Date d1, Date d2)
{
   return d1 >= d2;
}

std::ostream &operator<<(std::ostream &os, Date date){
   return os << date.toString();
}

/*
 * TODO function
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function is a reasonably literal translation of the old rhyme:
 *
 *    Thirty days has September
 *    April, June, and November
 *    All the rest have 31
 *    Excepting February alone
 *    Which has 28 in fine
 *    And each leap year 29
 */

int daysInMonth(Month month, int year)
{
   switch (month)
   {
   case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
      return 30;
   case JANUARY: case MARCH: case MAY: case JULY: case AUGUST: case OCTOBER: case DECEMBER:
      return 31;
   case FEBRUARY:
      if (isLeapYear(year)) return 29;
      else return 28;
   default:
      return -1;
   }
}

/* TODO PART:
 * Implementation notes: isLeapYear
 * --------------------------------
 * This function simply encodes the rule for determining leap years:
 * a leap year is any year divisible by 4, except for years ending in 00,
 * in which case the year must be divisible by 400.
 */

bool isLeapYear(int year)
{
   if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
      return true;
   }
   return false;
}

/* DO NOT modify this main() part */
int main()
{
   Date test(28, OCTOBER, 2022);
   cout << test.getYear() << endl;
   cout << test.toString() << endl;
}
