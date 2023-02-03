#include <iostream>
#include "date.hpp"

using namespace std;

bool is_a_leap_year(int y);

void date::set_date(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

date::date(int y, int m, int d) {
  set_date(y,m,d);
}

int date::get_year() {
	return year;
}
int date::get_month() {
	return month;
}
int date::get_day() {
	return day;
}


date::date() {

}

date::~date() {

}

int date::get_date_number() {
  // days due to completed years
  int accumulated_days = (year - 2000) * 365;
  // days due to completed!! leap years
  for (int ty = 2000 ; ty < year; ty++) {
    if (is_a_leap_year(ty)) {
      accumulated_days++;
    }
  }

  // capture the real world data in a "natural" way
  int month_length[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  for (int mt = 0; mt < month - 1; mt++) {
    accumulated_days += month_length[mt];
  }

  // deal with the possibility that the date is in a leap year
  // and we are on or after february

  if ((is_a_leap_year(year)) && (month > 2)) {
    accumulated_days++;
  }

  accumulated_days += day-1;

  // if we can be sure that the date is legitimate, then we are done

  return accumulated_days; // placeholder
}

// diagnostics stuff only
void date::print_diagnostics() {
  cout << "Values: year: " << year << ", month: " << month << ", day: " << day << "." << endl;
}

bool is_a_leap_year(int y) {
  bool r = false;
  if ((y % 4) == 0) {
    r = true;
  }
  if ((y % 100) == 0) {
    r = false;
  }
  if ((y % 400) == 0) {
    r = true;
  }
  return r;
}
