#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class BSTNode {
public:
  BSTNode(string newData);
  BSTNode(BSTNode &copy);
  ~BSTNode();

  string getData();
  BSTNode *&getLeft();
  BSTNode *&getRight();

  void setData(string newData);
  void setRight(BSTNode *newRight);
  void setLeft(BSTNode *newLeft);

private:
  string data;
  BSTNode *left;
  BSTNode *right;
};

ostream &operator<< (ostream &lhs, BSTNode &rhs);
