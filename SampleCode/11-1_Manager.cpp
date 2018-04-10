#include "Manager.h"

//Manager::Manager(const string &newName,
//	const double &newPayRate,
//	const double &newHours,
//	const bool &newSalariedEmployee)
//{
//
//}


// as of 3/26 this function is incomplete
Manager::~Manager() // completed 3/28
{
	cout << "Manager destructor" << endl;
}

// as of 3/26 this function is incomplete
bool Manager::getIsSalaried() // completed 3/28
{
	return this->mIsSalaried;
}

// as of 3/26 this function is incomplete
void Manager::setIsSalaried(bool newIsSalaried) // completed 3/28
{
	this->mIsSalaried = newIsSalaried;
}

// as of 3/26 this function is incomplete
double Manager::calculatePay() // completed 3/28
{
	double pay = 0.0;
	//this->

	if (!this->mIsSalaried)
	{
		// hourly employee
		pay = Employee::calculatePay();
		// if the data members are protected in the Employee
		// class, then the Manager () could directly access them
		// without using the public functions
		//pay = this->mPayRate * this->mHours;
	}
	else
	{
		// salaried manager
		pay = this->getPayRate();
	}

	return pay;
}