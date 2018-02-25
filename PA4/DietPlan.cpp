/*
Programming Assignment 4
Date : Feb 23, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program is a basic fitness application.
The user of the application to manually edit “diet” and “exercise” plans.
*/

#include "DietPlan.h"

DietPlan::DietPlan () {
  goalCal = 0;
  namePlan = "";
  datePlan = "";
}

DietPlan::DietPlan (DietPlan &copy) {
  goalCal = copy.getGoal();
  namePlan = copy.getName();
  datePlan = copy.getDate();
}

DietPlan::~DietPlan () {
    delete &goalCal;
    delete &namePlan;
    delete &datePlan;
}

int DietPlan::getGoal() const {
  return goalCal;
}

string DietPlan::getName() const {
  return namePlan;
}

string DietPlan::getDate() const {
  return datePlan;
}

void DietPlan::setGoal(int newGoal) {
  goalCal = newGoal;
}

void DietPlan::setName(string newName) {
  namePlan = newName;
}

void DietPlan::setDate(string newDate) {
  datePlan = newDate;
}

void DietPlan::editGoal () {
  int newGoal;
  cout << "Your current goal is : " << goalCal << endl;
  cout << "Your new goal is : ";
  cin >> newGoal;
  goalCal = newGoal;
}

// non members
fstream & operator>> (fstream &fileStream, DietPlan &plan) {
  string tempStr;
  int tempInt;
  // name
  getline(fileStream, tempStr);
  plan.setName(tempStr);
  // goal
  getline(fileStream, tempStr);
  std::stringstream streamInt(tempStr);
  streamInt >> tempInt;
  plan.setGoal(tempInt);
  // date
  getline(fileStream, tempStr);
  plan.setDate(tempStr);
  // check EOF
  if (!fileStream.eof())
    getline(fileStream, tempStr);
  return fileStream;
}

ostream & operator<< (ostream &lhs, const DietPlan &rhs) {
  lhs << rhs.getName() << "\t" << rhs.getGoal() << "\t" << rhs.getDate();
  return lhs;
}

fstream & operator<< (fstream &lhs, const DietPlan &rhs) {
  lhs << rhs.getName() << "\n" << rhs.getGoal() << "\n" << rhs.getDate() << "\n\n";
  return lhs;
}
