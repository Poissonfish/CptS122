///////////////////////////////////////////////////////////////////////////////
/// \file         
/// \author       AO
/// \date         
/// \brief   You are to write a basic fitness application, in C++, 
///          that allows the user of the application to manually edit 
///          “diet” and “exercise” plans.For this application you will 
///          need to create three classes : DietPlan, ExercisePlan, and FitnessAppWrapper.     
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdlib> // to use system("cls");

#include "DietPlan.h"
#include "ExcercisePlan.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // default constructor
	~FitnessAppWrapper(); // destructor

	void runApp(); // will drive the application
	void performUserSelection(const int &option);

	void loadWeeklyDietPlan(); // this will call the private loadWeeklyPlan() function
	void displayWeeklyDietPlan(); // this will call the private displayWeeklyPlan() function
	void storeWeeklyDietPlan(); // this will call the private storeWeeklyPlan() function
	bool editDietPlan(); // will prompt the user for the name of the plan to edit

private:
	DietPlan mDPList[7]; // will store the weekly list of DietPlan objects - 1 week = 7 days

	fstream mFstrDP;    // stream object for input/output to dietPlans.txt

	// private helper/utility functions
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void displayDailyPlan(const DietPlan &plan);
	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void storeDailyPlan(fstream &fileStream, const DietPlan &plan);
	void storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[]);

	void displayMenu();
};