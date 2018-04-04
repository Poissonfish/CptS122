#include "Data.h"

// copy constructor
Data::Data(Data &newData)
{
	//this->mNum = newData.getRational();
	
	*this = newData; // are we ok here? Which operator is this = ?
}

Data & Data::operator= (Data &newData)
{
	if (this != &newData) // check for self assignment!
	{
		this->setRational(newData.getRational());
	}

	return *this;
}

Rational Data::getRational()
{
	return this->mNum;
}

void Data::setRational(Rational &newRational)
{
	this->mNum = newRational; // this is the operator= that belongs to Rational!
}

bool operator< (Data &lhs, Data &rhs)
{
	bool compare = false;

	// the arithmetic is used to find a common denominator!
	if ((lhs.getRational().getNumerator () * rhs.getRational().getDenominator())
		< (rhs.getRational().getNumerator () * lhs.getRational().getDenominator())) 
	{
		compare = true;
	}

	return compare;
}