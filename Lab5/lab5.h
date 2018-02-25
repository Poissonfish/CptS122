#pragma once

#include <iostream>

using std::cout; // allow for us to now use cout << instead of std::cout <<
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Complex {
public:
  // Constructor/Destructor
  Complex();
  Complex(double real, double image);

  // Overloaded assignment operator
  Complex & operator= (const Complex &rhs);

  // Getter/setters
  double getRealPart() const;
  double getImaginaryPart() const;

  void setRealPart(double newReal);
  void setImaginaryPart(double newImage);

  // void Read();
  void Print();
  Complex Add(const Complex &rhs);
  // Sub();

private:
  double realPart;
  double imaginaryPart;
};

Complex Add(Complex &rhs, Complex &lhs);
Complex operator+ (const Complex &lhs, const Complex &rhs);
Complex operator- (const Complex &lhs, const Complex &rhs);
istream & operator>> (istream &lhs, const Complex &rhs);
