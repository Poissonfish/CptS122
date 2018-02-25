// In this example we are working with our first class called Rectangle.

// History: 2/14 - Created our first function template called
//                 addition (). Introduced std::string.
//          2/12 - Declared and defined overloaded assignment (=) and
//                 overloaded stream insertion (<<) operator for Rectangle objects
//          2/9 - Declared and defined destructor, copy constructor, and
//                computeArea ().
//          2/7 - Declared class Rectangle. Implemented setters/getters,
//                and the default constructor.

#include "6-1_Rectangle.h"
#include "6-1_Rectangle.cpp"

#include <string>
using std::string;

int main(void)
{
	// Since additon () is a function template, the compiler
	// will generate a specific instance of a definition for
	// it based on the actual arguments used in the function call!
	cout << "Result of integer addition: " << addition(5, 6) << endl;

	cout << "Result of double addition: " << addition(5.5, 6.55) << endl;

	string s1 = "string1", s2 = "string2";

	s1 = s2;
	//s1.operator+=

	cout << "Result of string addition: " << addition(s1, s2) << endl;

	// r1 is an object
	Rectangle r1;// constructor is called implicitly!
	r1.setWidth(5.0);
	r1.setLength(7.0);
	std::cout << "width: " << r1.getWidth() << std::endl;


	Rectangle r2 = r1; // copy constructor is called implicitly!
	cout << "area r2: " << r2.computeArea() << std::endl;

	// cout << "Result of rectangle addition: " << addition(r1, r2) << std::endl;

	r1 = r2; // shallow copy, member wise assignment

	cout << r1 << endl;

	return 0;
}
