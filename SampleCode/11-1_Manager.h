// History: 3/26 - declared the private data member in Manager and
//          corresponding operations.

#pragma once

#include <iostream>
#include <string>

#include "Employee.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Manager is a derived class, it's derived from Employee - need to complete the inheritance in class
class Manager : public Employee // added 3/26
{
public:
	Manager(const string &newName = "",
		const double &newPayRate = 0.0,
		const double &newHours = 0,
		const bool &newSalariedEmployee = false) : Employee(newName,
			newPayRate, newHours) // added 3/26 
	{
		this->mIsSalaried = newSalariedEmployee;
	} // we are using the Employee's constructor in initialize
	// the Employee parts of the Manager object!!!

	~Manager();

	// With inheritance, we should NOT have to redefine
	// many of the functions that we find in the Employee
	// class!
	bool getIsSalaried(); // added 3/26
	void setIsSalaried(bool newIsSalaried); // added 3/26

	double calculatePay(); // added 3/26

private:
	bool mIsSalaried;

};