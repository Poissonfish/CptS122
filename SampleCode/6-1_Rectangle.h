#pragma once

#include <iostream>

using std::cout; // allow for us to now use cout << instead of std::cout <<
using std::cin;
using std::endl;
using std::ostream;

//using namespace std; - don't do this!

class Rectangle
{
public:

	// all functions here are considered member functions

	// constructor
	Rectangle(); // default constructor
	// copy constructor
	Rectangle(Rectangle &copy);
	// destructor
	~Rectangle(); // clean up resources, i.e. heap memory, streams

	// overloaded assignment operator - function
	Rectangle & operator= (const Rectangle &rhs);

	// getters/setters - accessors/mutators
	double getLength() const; // constant function
	double getWidth() const;

	void setLength(double newLength);
	void setWidth(double newWidth);

	double computeArea();

private:
	double mLength; // data members
	double mWidth;
};

ostream & operator<< (ostream &lhs, Rectangle &rhs);

// Below is a function template. Function templates
// must be placed in the .h file
template <class T>
T addition(T obj1, T obj2)
{
	return obj1 + obj2;
}
