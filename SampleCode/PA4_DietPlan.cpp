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

#include "DietPlan.h"

///////////////////////// Member functions ///////////////////////////////////////////

DietPlan::DietPlan(const string &newPlanName, const string &newDate, const int &newGoalCalories)
{
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	this->mGoalCalories = newGoalCalories;
	cout << "Inside DietPlan's constructor!" << endl;
}

DietPlan::DietPlan(const DietPlan &copy)
{
	this->mPlanName = copy.mPlanName;  // this is copy a std::string to another one; std::string is an object, 
	                             // so the overloaded assignment for one is called here!
	this->mDate = copy.mDate;  // calls std::string overloaded assignment operator!
	this->mGoalCalories = copy.mGoalCalories;  // simple assignment between integers
}

DietPlan::~DietPlan()
{
	// the DietPlan objects will be stored in an array in the 
	// fitnessAppWrapper class
	cout << "Inside of DietPlan's destructor!" << endl;
}

DietPlan & DietPlan::operator= (const DietPlan &rhs)
{
	// check for self assignment
	if (this != &rhs) // the & here is the "address of" operator
	{
		// we are not peforming self-assignment if inside here
		this->mPlanName = rhs.mPlanName;  // this is copy a std::string to another one; std::string is an object, 
									 // so the overloaded assignment (=) for one is called here!
		this->mDate = rhs.mDate;  // calls std::string overloaded assignment (=) operator!
		this->mGoalCalories = rhs.mGoalCalories;  // simple assignment between integers
	}

	return (*this);
}

// getters - allows us to return a copy of the private data members to outside the object
string DietPlan::getPlanName() const // const member function - should not modify data in object - if try to, compiler will provide error!
{
	return this->mPlanName;
}

string DietPlan::getDate() const
{
	return this->mDate;
}

int DietPlan::getGoalCalories() const
{
	return this->mGoalCalories;
}

// setters - allows us to modify the private data members with values from outside the object
void DietPlan::setPlanName(const string &newPlanName)
{
	this->mPlanName = newPlanName; // calls std::string overloaded assignment (=) operator
}

void DietPlan::setDate(const string &newDate)
{
	this->mDate = newDate; // calls std::string overloaded assignment (=) operator
}

void DietPlan::setGoalCalories(const int &newGoalCalories)
{
	this->mGoalCalories = newGoalCalories;
}

void DietPlan::editGoal() // prompt the user for a different goal - display plan with changes to screen
{
	cout << "Please enter a new calories goal: ";
	cin >> this->mGoalCalories;

	cout << (*this) << endl; // can use "*this" here because we've overloaded the stream insertion << (ostream, DietPlan) 
	                         // and we want to see the current object's plan details
}



///////////////////////// nonmember functions /////////////////////////////////////

// format: Plan Name
//         Goal Calories
//         Date

ostream & operator<< (ostream &lhs, const DietPlan &rhs)  // will allow cout << DietPlan object1 << DietPlan object2...
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions cout << DietPlan object1 << DietPlan object2...
}

// format: Plan Name
//         Goal Calories
//         Date

fstream & operator<< (fstream &lhs, const DietPlan &rhs) // will allow fstr << DietPlan object1 << DietPlan object2... 
{
	// cast lhs to ofstream so can easily output std::string (plan name)
	((ofstream &) (lhs)) << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions fstr << DietPlan object1 << DietPlan object2...
}

// format: Plan Name
//         Goal Calories
//         Date

// Note: "rhs" can't be const because we are modifying the object
// when we peform a stream extraction operation.
fstream & operator>> (fstream &lhs, DietPlan &rhs) // will allow fstr >> DietPlan object1 >> DietPlan object2...
{
	char tempString[100] = "";
	lhs.getline (tempString, 100); // read the plan name, including the newline in the file
	rhs.setPlanName(tempString); // when the char * is passed into setPlanName a std::string is constructed and
	                             // initialized with the char * value 
	int goalCalories = 0;
	lhs.getline(tempString, 100);  // read the goal calories line as a string, then convert to an integer, this way we can read in the newline
	goalCalories = atoi(tempString); // convert the char * string representation to its corresponding integer, i.e. "42" to 42 int
	rhs.setGoalCalories(goalCalories);
	lhs.getline(tempString, 100);  // read the date from the file, also reads newline
	rhs.setDate(tempString);

	return lhs; // allows for chaining of stream extractions fstr >> DietPlan object1 >> DietPlan object2...
}