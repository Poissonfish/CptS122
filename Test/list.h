#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class List {
public:
  List(int a, int b);
  List(const List &copy);
  ~List();
private:
  int a;
  int b;
};
