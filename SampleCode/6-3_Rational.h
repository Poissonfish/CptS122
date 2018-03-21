// We will place each class declaration
// in a separate .h file. Each .h file
// will be named the same as the class.

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::endl;
using std::cin;
// Blueprint for a rational number
class Rational
{
public:
	// In here will be our well defined interfaces
	// to the object - member functions

	//Rational();
	//Rational(int newNumerator, int newDenominator);
	// constructor with default arguments
	Rational(int newNumerator = 0, int newDenominator = 1);

	// copy constructor - pass-by-value
	Rational(Rational &copy);

	~Rational(); // destructor

	Rational & operator= (Rational &rhs);

	Rational add(Rational rhs);

	// getters/accessors
	int getNumerator() const; // constant function - cant change data members
	int getDenominator() const;

	// setters/mutators
	void setNumerator(int newNumerator);
	void setDenominator(int newDenominator);

	//Rational add(Rational lhs, Rational rhs);

private:
	// attributes - data members
	// rational numbers may defined as:
	// numerator / denominator
	int mNumerator;
	int mDenominator;
};

// non member
Rational operator+ (Rational &lhs, Rational &rhs);
std::ifstream & operator>> (std::ifstream &lhs, Rational &rhs);
bool operator==(const Rational &lhs, const Rational &rhs);

// function template - outline for a function
// the type T is replace by a specific type based
// on the actual argument types used - the compiler
// will generate all instances of the function based on
// the actual argument types!
template <class T> // <typename T>
bool compare(const T &lhs, const T &rhs)
{
	// bool - true/false
	return (lhs == rhs);
}

