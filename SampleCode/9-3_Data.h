#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Rational.h"

class Data
{
public:

	Data()
	{

	}

	Data(Data &newData);

	Data & operator= (Data &newData);

	Rational getRational();
	void setRational(Rational &newRational);

private:
	Rational mNum;
};

// non member
bool operator< (Data &lhs, Data &rhs);