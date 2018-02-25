#include "lab5.h"
#include "lab5.cpp"

#include <string>
using std::string;

int main(void) {
  Complex c1(3.5, 2), c2(5.5, 7);
  Complex c3, c4, c5, c6, c7, c8;

  // (a)
  c3 = c1.Add(c2);  // member add () function
  cout << "c3: " << c3 << endl;
  c4 = Add(c1, c2); // non-member add () function
  cout << "c4: " << c4 << endl;
  c5 = c1 + c2;       // overloaded + operator
  cout << "c5: " << c5 << endl;

  // (b)
  c6 = c1 - c2;
  cout << "c6: " << c6 << endl;

  // I have no idea how to cast cin to a string
  // (c)
  // cout << “Enter a complex number in the form a + bi: “;
  // c1.read();
  // cout << “Enter a complex number in the form a + bi: “;
  // c2.read();
  //
  // cout << “Enter two complex numbers in the form a + bi (each separated by whitespace): “;
  // cin >> c1 >> c2;

  // (d)
  c1.Print();
  c2.Print();
  c3.Print();
  cout << c1 << " " << c2 << " " << c3 << endl;

}
