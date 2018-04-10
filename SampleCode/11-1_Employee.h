#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Employee is a base class
class Employee
{
	// We will not use any qualifiers (i.e. like const) in this example to simplify
public:
	Employee(const string &newName = "", 
		const double &newPayRate = 8.55, 
		const double &newHours = 0.0);
	~Employee();

	string getName();
	double getPayRate();
	double getHours();

	void setName(const string &newName);
	void setPayRate(const double &newPayRate);
	void setHours(const double &newHours);

	// virtual provides the ability to override the function
	// calculatePay (), allowing for polymorphic behavior
	// pure virtual function
	virtual double calculatePay() = 0; // abstract class; Employee
	               // objects can no longer be instantiated

private:
	string mName;
	double mPayRate;
	double mHours;
};