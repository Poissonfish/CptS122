/*
Programming Assignment 4
Date : Feb 23, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program is a basic fitness application.
The user of the application to manually edit “diet” and “exercise” plans.
*/

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>

#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

class FitnessAppWrapper {
public:
  FitnessAppWrapper();
  // Load the information from file to an array
  void loadDailyPlan (fstream &fileStream, DietPlan &plan);
  void loadDailyPlan (fstream &fileStream, ExercisePlan &plan);
  void loadWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[]);
  void loadWeeklyPlan (fstream &fileStream, ExercisePlan weeklyPlan[]);

  // Display the information from an array
  void displayDailyPlan(DietPlan &plan);
  void displayDailyPlan(ExercisePlan &plan);
  void displayWeeklyPlan(DietPlan plan[]);
  void displayWeeklyPlan(ExercisePlan plan[]);

  // Edit specific record in an array
  void editDiet(DietPlan weeklyPlan[]);
  void editExercise(ExercisePlan weeklyPlan[]);

  // Store the array to file
  void storeDailyPlan (fstream &fileStream, DietPlan &plan);
  void storeDailyPlan (fstream &fileStream, ExercisePlan &plan);
  void storeWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[]);
  void storeWeeklyPlan (fstream &fileStream, ExercisePlan weeklyPlan[]);

  // Display the menu 
  void displayMenu ();
  // Get option from user and implement the feature
  int getMenuOption() const;
  // Clean the screen
  void clean () const;
  // Pause the program until <enter> input
  void stop ();
  // Run the app
  void runApp (void);

private:
  DietPlan *dietPlan;
  ExercisePlan *exercisePlan;
  fstream fileDiet;
  fstream fileExercise;
  int dietLoaded;
  int exerciseLoaded;
};
