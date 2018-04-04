
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <class T, class U>
T add (T a, T b) {
  return a + b;
}
template <class T, class U>
T add (T a, U b) {
  return a + b;
}
