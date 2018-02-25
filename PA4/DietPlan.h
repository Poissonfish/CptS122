/*
Programming Assignment 4
Date : Feb 23, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program is a basic fitness application.
The user of the application to manually edit �diet� and �exercise� plans.
*/
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
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ostream;

class DietPlan
{
public:
  DietPlan();
  DietPlan(DietPlan &copy);
  ~DietPlan();

  // Getter
  int getGoal() const;
  string getName() const;
  string getDate() const;

  // Setter
  void setGoal(int newGoal);
  void setName(string newName);
  void setDate(string newDate);

  // Allow user to modify the goal and display the updated one
  void editGoal();

private:
    int goalCal;
    string namePlan;
    string datePlan;
};

fstream & operator>> (fstream &fileStream, DietPlan &plan);
fstream & operator<< (fstream &lhs, const DietPlan &rhs);
ostream & operator<< (ostream &lhs, const DietPlan &rhs);