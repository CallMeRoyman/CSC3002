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
   month = Month(month + 1);
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
   Month month = JANUARY;
   int days = dayInYear;
   while (days > daysInMonth(month,year)){
      days -= daysInMonth(month,year);
      month++;
   }
   return days;
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
   Month month = JANUARY;
   int days = dayInYear;
   while (days > daysInMonth(month,year)){
      days -= daysInMonth(month,year);
      month++;
   }
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
   return dd + "-" + mmm + "-" + yyyy;
}

string Date::capitalize(string str)
{
   string Str = "";
   Str += toupper(str[0]);
   if (str.length() > 1) Str += toLowerCase(str.substr(1, 2));
   return Str;
}

void Date::initDate(int day, Month month, int yyyy)
{
    if (day < 1 ) {
          error("Specified date does not exist in the calendar");
      }
   if (day > daysInMonth(month,yyyy)){
      error("Specified date does not exist in the calendar");
      while(day > daysInMonth(month,year)){
               day -= daysInMonth(month,year);
               month++;
               if(month>12){
                 year++;
                 month=JANUARY;
               }
      }
   }
      this->day = day;
      dayInYear = day;
      this->month = month;
      for (Month m = JANUARY; m < month; m++) {
         dayInYear += daysInMonth(m, yyyy);
      }
      year = yyyy;
}

Date operator+(Date date, int delta)
{
   int days = date.getDay();
   Month mon = date.getMonth();
   int year = date.getYear();
   days += delta;
   if (days>daysInMonth(mon,year)){
            while(days>daysInMonth(mon,year)){
               days-=daysInMonth(mon,year);
               mon++;
               if(mon>12){
                 year++;
                 mon=JANUARY;
               }
            }    
   }
   return Date(days,mon,year);
}

Date operator-(Date date, int delta)
{
   int days = date.getDay();
   Month mon = date.getMonth();
   int year = date.getYear();
   days -= delta;
   if (days <= 0){
         while(days <= 0){
            days+=daysInMonth(mon,year);
            mon=Month(mon-1);
            if(mon<1){
               year--;
               mon=DECEMBER;
            }   
         }
   } 
   return Date(days,mon,year);
}

int operator-(Date d1, Date d2)
{
   int delday=0;
   int del=0;
   while(d1!=d2){
      del++;
      if (d1+del==d2){
         delday = -del;
         break;
         }
      else if (d2+del==d1){
         delday = del;
         break;
         }
   }
   return delday;
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
   if (d1.getDay()==d2.getDay()&&d1.getMonth()==d2.getMonth()&&d1.getYear()==d2.getYear()){
      return true;
   }
   return false;
}

bool operator!=(Date d1, Date d2)
{
   if (d1.getDay()!=d2.getDay()||d1.getMonth()!=d2.getMonth()||d1.getYear()!=d2.getYear()){
      return true;
   }
   return false;
}

bool operator<(Date d1, Date d2)
{
   if (d1 - d2 < 0){
      return true;
   }
   return false;
}

bool operator<=(Date d1, Date d2)
{
   if (d1 - d2 <= 0){
      return true;
   }
   return false;
}

bool operator>(Date d1, Date d2)
{
   if (d1 - d2 > 0){
      return true;
   }
   return false;
}

bool operator>=(Date d1, Date d2)
{
   if (d1 - d2 >= 0){
      return true;
   }
   return false;
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
   int id;
   cin >> id;
   int day, year;
   string mon;
   cin >> day >> mon >> year;

   if (id == 1)
   {
      for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1))
      {
         cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << endl;
      }
   }
   else if (id == 2)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding.toString() << endl;
   }
   else if (id == 3)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cin >> mon >> day >> year;
      Date kennedyAssassination(stringToMonth(mon), day, year);
      cin >> mon >> day >> year;
      Date newYearsEve(stringToMonth(mon), day, year);
      cin >> day >> mon >> year;
      Date inaugurationDay(day, stringToMonth(mon), year);
      cin >> day >> mon >> year;
      Date electionDay(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding << endl;
      cout << "kennedyAssassination = " << kennedyAssassination << endl;
      cout << boolalpha;
      cout << "moonLanding < kennedyAssassination = "
           << (moonLanding < kennedyAssassination) << endl;
      cout << "moonLanding > kennedyAssassination = "
           << (moonLanding > kennedyAssassination) << endl;
      cout << "moonLanding == kennedyAssassination = "
           << (moonLanding == kennedyAssassination) << endl;
      cout << "moonLanding == moonLanding = "
           << (moonLanding == moonLanding) << endl;
      cout << "inaugurationDay - electionDay = "
           << (inaugurationDay - electionDay) << endl;
      Date day = newYearsEve;
      cout << "New Year's Eve = " << day++ << endl;
      cout << "New Year's Day = " << day << endl;
      for (Date d = electionDay; d <= inaugurationDay; d++)
      {
         cout << d << endl;
      }
   }
}
