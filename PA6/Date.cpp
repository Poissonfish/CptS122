#include "Date.hpp"

Date::Date() {
  time_t t = time(0);
  struct tm *now = localtime(&t);
  this->year = now->tm_year + 1900;
  this->month = now->tm_mon + 1;
  this->day = now->tm_mday;
  this->date = itos(this->year) + "/" + itos(this->month) + "/" + itos(this->day);
}

// deep copy
Date::Date(const Date &copy) {
  this->year = copy.getYear();
  this->month = copy.getMonth();
  this->day = copy.getDay();
  this->date = itos(this->year) + "/" + itos(this->month) + "/" + itos(this->day);
}

Date::~Date() {
  delete &(this->year);
  delete &(this->month);
  delete &(this->day);
  delete &(this->date);
}

string Date::getDate() const {
  return this->date;
}

int Date::getYear() const {
  return this->year;
}

int Date::getMonth() const {
  return this->month;
}

int Date::getDay() const {
  return this->day;
}

void Date::updateDate() {
  this->date = itos(this->year) + "/" + itos(this->month) + "/" + itos(this->day);
}

void Date::setYear(int year) {
  this->year = year;
  updateDate();
}

void Date::setMonth(int month) {
  this->month = month;
  updateDate();
}

void Date::setDay(int day) {
  this->day = day;
  updateDate();
}

void Date::setDate(string date) {
    string delim = "/";
    int pos = -1;
    string token;
    // get date
    this->date = date;
    // get year
    pos = date.find(delim);
    token = date.substr(0, pos);
    this->year = std::stoi(token);
    date.erase(0, pos + delim.length());
    // get month
    pos = date.find(delim);
    token = date.substr(0, pos);
    this->month = std::stoi(token);
    date.erase(0, pos + delim.length());
    // get day
    this->day = std::stoi(date);

}

// convert an integer to a string
string itos(int integer) {
  std::stringstream stream;
  stream << integer;
  return stream.str();
}

ostream & operator<< (ostream &lhs, const Date &rhs) {
    lhs << rhs.getYear() << "/" << rhs.getMonth() << "/" << rhs.getDay();
    return lhs;
}

fstream & operator<< (fstream &lhs, const Date &rhs) {
    lhs << rhs.getYear() << "/" << rhs.getMonth() << "/" << rhs.getDay();
    return lhs;
}
