#pragma once

#include "Manager.h"

class Officer : protected Manager // added 3/30
{
public:
	Officer(const string &newName = "",
		const double &newPayRate = 0.0,
		const double &newHours = 0,
		const bool &newSalariedEmployee = false,
		const string &newTitle = "") :
		Manager(newName, newPayRate, newHours, newSalariedEmployee)
	{
		mTitle = newTitle;
	}

private: 
	string mTitle;
};