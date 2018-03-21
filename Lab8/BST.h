#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class BST {
public:
  BST();
  BST(BST &copy);
  ~BST();

  void insertNode(string newData);
  void inOrderTraversal();
  void preOrderTraversal();
  void postOrderTraversal();
  bool isEmpty();

private:
  BSTNode *mpRoot;
  BSTNode *copyTreeHelper(BSTNode *&currentNode) {
  void destroyTreeHelper(BSTNode *currentNode);
  void insertNode(BSTNode *&currentNode, string newData);
  void inOrderTraversal(BSTNode *currentNode);
  void preOrderTraversal(BSTNode *currentNode);
  void postOrderTraversal(BSTNode *currentNode);
};
