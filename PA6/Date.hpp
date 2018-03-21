#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;

class Date {
public:
    Date();
    Date(const Date &copy);
    ~Date();

    // getter
    string getDate() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    // setter
    void setDate(string date);
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    // update the date string based on other three members
    void updateDate();

private:
    string date;
    int year;
    int month;
    int day;
};

string itos(int integer);
ostream & operator<< (ostream &lhs, const Date &rhs);
fstream & operator<< (fstream &lhs, const Date &rhs);
