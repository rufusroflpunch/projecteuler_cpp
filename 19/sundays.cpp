/*
 * Project Euler
 * Problem 19
 *
 * How many Sundays fell on the first of the month during
 * the twentieth century (1 Jan 1901 to 31 Dec 2000)
 *
 */

#include <iostream>
#include <vector>
using namespace std;


inline bool is_leap_year(int &year){ return (year - 1900) % 4 == 0; };

int main() {
  int month = 1, day = 1, year = 1901, day_week = 3; // Tue, Jan 1, 1901
  int sundays = 0; // Sunday counter

  auto inc_day = [&month, &day, &year, &day_week]() {
    if (day == 31 && month == 12) { month = 1; day = 1; year++; cout << "Happy new year!" << endl; }
    else if (day == 30 &&
        (month == 4 || month == 6 || month == 9 || month == 11)) {
      day = 1; month++;
    }
    else if (day == 31 && month != 2) { day = 1; month++; }
    else if (day == 28 && month == 2 && !is_leap_year(year)) { day = 1; month++; }
    else if (day == 29 && month == 2 && is_leap_year(year)) { day = 1; month++; }
    else day++;

    if (day_week < 7) day_week++;
    else { day_week = 1; }
  };

  while (year < 2001) {
    inc_day();
    if (day == 1 && day_week == 1) {
      cout << "Sunday: " << month << "-" << day << "-" << year << endl;
      sundays++;
    }
  }

  cout << "Number of sundays on first of month: " << sundays << endl;
  return 0;
}
