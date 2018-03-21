#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <istream>

#include "Date.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::fstream;

class Stack {
public:
    Stack();
    Stack(const Stack &copy);
    ~Stack();

    // getter
    int getSize()const;
    // is the stack empty
    bool isEmpty();

    // push the data at front
    void push(Date * &newDate);
    // remove the data at front and return the value
    Date *pop();
    // return the data at front
    Date *peek();

    // for bonus
    // print the stack
    void printStack();
    // remove the stack content at given position
    void removeAtN(int n);

private:
  Date *node;
  int size;
};
