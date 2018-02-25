#include "lab5.h"

Complex::Complex(double real, double image) {
  realPart = real;
  imaginaryPart = image;
}

Complex::Complex() {
  realPart = 0.0;
  imaginaryPart = 0.0;
}

Complex & Complex::operator= (const Complex &rhs) {
  imaginaryPart = rhs.getImaginaryPart();
  realPart = rhs.getRealPart();
  return (*this);
}

double Complex::getRealPart() const {
  return realPart;
}

double Complex::getImaginaryPart() const {
  return imaginaryPart;
}

void Complex::setRealPart(double newReal) {
  realPart = newReal;
}

void Complex::setImaginaryPart(double newImage) {
  imaginaryPart = newImage;
}

Complex Complex::Add(const Complex &rhs) {
  Complex newC;
  newC.setRealPart(realPart + rhs.getRealPart());
  newC.setImaginaryPart(imaginaryPart + rhs.getImaginaryPart());
  return newC;
}

// void Complex::read()

Complex Add(Complex &rhs, Complex &lhs) {
  Complex newC;
  newC.setRealPart(rhs.getRealPart() + lhs.getRealPart());
  newC.setImaginaryPart(rhs.getImaginaryPart() + lhs.getImaginaryPart());
  return newC;
}

Complex operator+ (const Complex &lhs, const Complex &rhs) {
  Complex newC;
  newC.setRealPart(rhs.getRealPart() + lhs.getRealPart());
  newC.setImaginaryPart(rhs.getImaginaryPart() + lhs.getImaginaryPart());
  return newC;
}

Complex operator- (const Complex &lhs, const Complex &rhs) {
  Complex newC;
  newC.setRealPart(lhs.getRealPart() - rhs.getRealPart());
  newC.setImaginaryPart(lhs.getImaginaryPart() - rhs.getImaginaryPart());
  return newC;
}

void Complex::Print() {
  cout << realPart << " + " << imaginaryPart << "i" << endl;
}

// non member
ostream & operator<< (ostream &lhs, const Complex &rhs)
{
	lhs << rhs.getRealPart() << " + " << rhs.getImaginaryPart() << "i";
	return lhs;
}

istream & operator>> (istream &lhs, Complex &rhs) {

  return lhs;
}
