/*
Programming Assignment 4
Date : Feb 23, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program is a basic fitness application.
The user of the application to manually edit “diet” and “exercise” plans.
*/

#include "ExercisePlan.h"

ExercisePlan::ExercisePlan () {
  goalStep = 0;
  namePlan = "";
  datePlan = "";
}

ExercisePlan::ExercisePlan (ExercisePlan &copy) {
  goalStep = copy.getGoal();
  namePlan = copy.getName();
  datePlan = copy.getDate();
}

ExercisePlan::~ExercisePlan () {
  delete &goalStep;
  delete &namePlan;
  delete &datePlan;
}

int ExercisePlan::getGoal() const {
  return goalStep;
}

string ExercisePlan::getName() const {
  return namePlan;
}

string ExercisePlan::getDate() const {
  return datePlan;
}

void ExercisePlan::setGoal(int newGoal) {
  goalStep = newGoal;
}

void ExercisePlan::setName(string newName) {
  namePlan = newName;
}

void ExercisePlan::setDate(string newDate) {
  datePlan = newDate;
}

void ExercisePlan::editGoal () {
  int newGoal;
  cout << "Your current goal is : " << goalStep << endl;
  cout << "Your new goal is : ";
  cin >> newGoal;
  goalStep = newGoal;
}

// non members
fstream & operator>> (fstream &fileStream, ExercisePlan &plan) {
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

ostream & operator<< (ostream &lhs, const ExercisePlan &rhs) {
  lhs << rhs.getName() << "\t" << rhs.getGoal() << "\t" << rhs.getDate();
  return lhs;
}

fstream & operator<< (fstream &lhs, const ExercisePlan &rhs) {
  lhs << rhs.getName() << "\n" << rhs.getGoal() << "\n" << rhs.getDate() << "\n\n";
  return lhs;
}
