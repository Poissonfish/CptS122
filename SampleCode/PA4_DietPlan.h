///////////////////////////////////////////////////////////////////////////////
/// \file         DietPlan.h
/// \author       AO
/// \date         
/// \brief        
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class DietPlan
{
public:
	// constructor with default arguments - when a DietPlan is constructed or 
	// instantiated we can supply values for each of the member variables or 
	// leave them as the default ones
	DietPlan(const string &newPlanName = "", const string &newDate = "", const int &newGoalCalories = 0);

	// copy constructor - invoked during the construction of an object, when the object is 
	// set to another object of same type; invoked when passing-by-value (making a copy)
	DietPlan(const DietPlan &copy);

	// destructor - invoked when an object leaves scope or is destroyed - if the object was 
	// created on the heap (dynamic), then a call to delete the object (using delete operator)
	// will implicitly invoke the constructor
	~DietPlan();

	// overloaded assignment - always a member function
	DietPlan & operator= (const DietPlan &rhs); 

	// getters - allows us to return a copy of the private data members to outside the object
	string getPlanName() const; // const member function - should not modify data in object - 
	                            // if try to, compiler will provide error!
	string getDate() const;
	int getGoalCalories() const;

	// setters - allows us to modify the private data members with values from 
	// outside the object
	void setPlanName(const string &newPlanName);
	void setDate(const string &newDate);
	void setGoalCalories(const int &newGoalCalories);

	void editGoal(); // prompt the user for a different goal - display plan with 
	                 // changes to screen

private:
	string mPlanName;
	string mDate;
	int mGoalCalories;
};

// nonmember functions
ostream & operator<< (ostream &lhs, const DietPlan &rhs); // will allow cout << DietPlan object1 << DietPlan object2...
// write a complete DietPlan to a file
fstream & operator<< (fstream &lhs, const DietPlan &rhs); // will allow fstr << DietPlan object1 << DietPlan object2... 
// read a complete DietPlan from a file
fstream & operator>> (fstream &lhs, DietPlan &rhs); // will allow fstr >> DietPlan object1 >> DietPlan object2...