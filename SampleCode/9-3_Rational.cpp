// We will place the definitions for only
// Rational's operations in this file

#include "Rational.h"

//Rational::Rational()
//{
//	mNumerator = 0;
//	mDenominator = 1;
//}
//
//Rational::Rational(int newNumerator, int newDenominator)
//{
//	mNumerator = newNumerator;
//	mDenominator = newDenominator;
//}

Rational::Rational(int newNumerator, int newDenominator)
{
	mNumerator = newNumerator;

	// validate the denominator
	if (newDenominator != 0)
	{
		mDenominator = newDenominator;
	}
	else
	{
		mDenominator = 1;
	}
}

int Rational::getNumerator() const
{
	return mNumerator;
}

int Rational::getDenominator() const
{
	return mDenominator;
}


void Rational::setNumerator(int newNumerator)
{
	mNumerator = newNumerator;
}

void Rational::setDenominator(int newDenominator)
{
	// validate the denominator
	if (newDenominator != 0)
	{
		mDenominator = newDenominator;
	}
}

// pass-by-value
Rational::Rational(Rational &copy)
{
	//mNumerator = copy.mNumerator;
	setNumerator(copy.getNumerator());
	setDenominator(copy.getDenominator());
}

Rational Rational::add(Rational rhs)
{
	Rational result;

	result.setDenominator(rhs.getDenominator() *
		getDenominator());
	result.setNumerator(rhs.getNumerator() * getDenominator() +
		getNumerator()*rhs.getDenominator());

	return result;
}

Rational::~Rational()
{
	//cout << "Inside destructor for Rational" << std::endl;
}

Rational & Rational::operator= (Rational &rhs)
{
	setNumerator(rhs.getNumerator());
	setDenominator(rhs.getDenominator());

	return (*this);
}

// this allows for r1 + r2
Rational operator+ (Rational &lhs, Rational &rhs)
{
	Rational result;

	result.setNumerator(lhs.getNumerator()*rhs.getDenominator() +
		rhs.getNumerator()*lhs.getDenominator());
	result.setDenominator(lhs.getDenominator() * rhs.getDenominator());

	return result;
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
	return (lhs.getNumerator()*rhs.getDenominator() ==
		rhs.getNumerator()*lhs.getDenominator());
}

// this allows for input >> r1
std::ifstream & operator >> (std::ifstream &lhs, Rational &rhs)
{
	// 5/9\n - is the format of the numbers in the file
	int numerator = 0, denominator = 0;
	char slash = '\0';

	lhs >> numerator;
	rhs.setNumerator(numerator);
	lhs >> slash;
	lhs >> denominator;
	rhs.setDenominator(denominator);

	return lhs;
}