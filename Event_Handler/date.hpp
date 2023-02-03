#pragma once
class date {
  private:
  int year;
  int month;
  int day; // day of month

  public:
  date(int y, int m, int d); // convenience constructor
  date(); //default constructor
  ~date();

  void set_date(int y, int m, int d);
  void print_diagnostics(); // diagnostic only -- show us the values in the date object

  // getters and setters should be here

  // methods we are required to implement
  int get_date_number();
  int get_year();
  int get_month();
  int get_day();
};
