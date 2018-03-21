/*
Programming Assignment 4
Date : Feb 23, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program is a basic fitness application.
The user of the application to manually edit �diet� and �exercise� plans.
*/

#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper() {
  dietPlan = new DietPlan[7];
  exercisePlan = new ExercisePlan[7];
  fileDiet.open("dietPlans.txt");
  fileExercise.open("exercisePlans.txt");
  dietLoaded = 0;
  exerciseLoaded = 0;
}

void FitnessAppWrapper::loadDailyPlan (fstream &fileStream, DietPlan &plan) {
  fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan (fstream &fileStream, ExercisePlan &plan) {
  fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[]) {
  for (int i = 0; i < 7; i ++)
    loadDailyPlan(fileStream, weeklyPlan[i]);
  fileStream.close();
  cout << "File is loaded!" << endl;
  stop();
  clean();
}

void FitnessAppWrapper::loadWeeklyPlan (fstream &fileStream, ExercisePlan weeklyPlan[]) {
  for (int i = 0; i < 7; i ++)
    loadDailyPlan(fileStream, weeklyPlan[i]);
  fileStream.close();
  cout << "File is loaded!" << endl;
  stop();
  clean();
}

void FitnessAppWrapper::displayDailyPlan(DietPlan &plan) {
  cout << plan << endl;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan &plan) {
  cout << plan << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan plan[]) {
  cout << "Here's your weekly diet plan :" << endl;
  for (int i = 0; i < 7; i ++)
    displayDailyPlan(plan[i]);
  stop();
  clean();
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan plan[]) {
  cout << "Here's your weekly exercise plan :" << endl;
  for (int i = 0; i < 7; i ++)
    displayDailyPlan(plan[i]);
  stop();
  clean();
}

void FitnessAppWrapper::editDiet(DietPlan weeklyPlan[]) {
  clean();
  int option = 0;
  cout << "Which goal of the day you want to edit ?" << endl;
  cout << "Please specify a day (1 ~ 7) : " << endl;
  cin >> option;
  weeklyPlan[option - 1].editGoal();
  cout << "\n It's your new plan : " << endl;
  displayDailyPlan(weeklyPlan[option - 1]);
  stop();
  clean();
}

void FitnessAppWrapper::editExercise(ExercisePlan weeklyPlan[]) {
  clean();
  int option = 0;
  cout << "Which goal of the day you want to edit ?" << endl;
  cout << "Please specify a day (1 ~ 7) : " << endl;
  cin >> option;
  weeklyPlan[option - 1].editGoal();
  cout << "\n It's your new plan : " << endl;
  displayDailyPlan(weeklyPlan[option - 1]);
  stop();
  clean();
}

void FitnessAppWrapper::storeDailyPlan (fstream &fileStream, DietPlan &plan) {
  fileStream << plan;
}

void FitnessAppWrapper::storeDailyPlan (fstream &fileStream, ExercisePlan &plan) {
  fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan (fstream &fileStream, DietPlan weeklyPlan[]) {
  fileStream.open("dietPlans.txt");
  for (int i = 0; i < 7; i ++)
    storeDailyPlan(fileStream, weeklyPlan[i]);
  fileStream.close();
  cout << "Diet plan has been saved!" << endl;
  stop();
  clean();
}

void FitnessAppWrapper::storeWeeklyPlan (fstream &fileStream, ExercisePlan weeklyPlan[]) {
  fileStream.open("exercisePlans.txt");
	for (int i = 0; i < 7; i ++)
    storeDailyPlan(fileStream, weeklyPlan[i]);
  fileStream.close();
  cout << "Exercise plan has been saved!" << endl;
  stop();
  clean();
}

void FitnessAppWrapper::displayMenu() {
  cout << "Hi, welcome to the heathy plan manager!" << endl;
  cout << "1. Load weekly diet plan from file." << endl;
  cout << "2. Load weekly exercise plan from file." << endl;
  cout << "3. Store weekly diet plan to file." << endl;
  cout << "4. Store weekly exercise plan to file." << endl;
  cout << "5. Display weekly diet plan to screen." << endl;
  cout << "6. Display weekly exercise plan to screen." << endl;
  cout << "7. Edit daily diet plan." << endl;
  cout << "8. Edit daily exercise plan." << endl;
  cout << "9. Exit." << endl;
  cout << "Please enter an option (1~9) : ";
}

int FitnessAppWrapper::getMxwenuOption() const {
  int option = 0;
  cin >> option;
  clean();
  return option;
}

void FitnessAppWrapper::clean() const {
   system("cls"); // Windows
  //system("clear"); // Mac
}

void FitnessAppWrapper::stop() {
	printf("\n<Press Enter to Continue>\n");
	getchar();
	getchar();
}

void FitnessAppWrapper::runApp () {
  int option = 0;
  while (option != 9) {
    displayMenu();
    option = getMenuOption();
    switch (option) {
      case 1: loadWeeklyPlan(fileDiet, dietPlan);
        dietLoaded = 1;
        break;
      case 2: loadWeeklyPlan(fileExercise, exercisePlan);
        exerciseLoaded = 1;
        break;
      case 3:
        if (dietLoaded)
          storeWeeklyPlan(fileDiet, dietPlan);
        else {
          clean();
          cout << "No diet plan loaded yet!" << endl;
          stop();
          clean();
        }
        break;
      case 4:
        if (exerciseLoaded)
          storeWeeklyPlan(fileExercise, exercisePlan);
        else {
          clean();
          cout << "No exercise plan loaded yet!" << endl;
          stop();
          clean();
        }
        break;
      case 5:
		if (dietLoaded)
		  displayWeeklyPlan(dietPlan);
		else {
			clean();
			cout << "No diet plan loaded yet!" << endl;
			stop();
			clean();
		}
        break;
      case 6:
		if (exerciseLoaded)
		  displayWeeklyPlan(exercisePlan);
		else {
			clean();
			cout << "No exercise plan loaded yet!" << endl;
			stop();
			clean();
		}
        break;
      case 7:
		if (dietLoaded)
		  editDiet(dietPlan);
		else {
			clean();
			cout << "No diet plan loaded yet!" << endl;
			stop();
			clean();
		}
        break;
      case 8:
        if (exerciseLoaded)
		  editExercise(exercisePlan);
		else {
			clean();
			cout << "No exercise plan loaded yet!" << endl;
			stop();
			clean();
		}
        break;
    }
  }
  storeWeeklyPlan(fileDiet, dietPlan);
  storeWeeklyPlan(fileExercise, exercisePlan);
  fileDiet.close();
  fileExercise.close();
}
