#include "BSTNode.h"

BSTNode::BSTNode(string newData) {
  this->data = newData;
  this->left = nullptr;
  this->right = nullptr;
}

BSTNode::BSTNode(BSTNode &copy) {
  this->data = copy.data;
  this->left = copy.left;
  this->right = copy.right;
}

BSTNode::~BSTNode() {
  // do nothing here
}

string BSTNode::getData() {
  return this->data;
}

BSTNode *&BSTNode::getLeft() {
  return this->left;
}

BSTNode *&BSTNode::getRight() {
  return this->right;
}

void BSTNode::setData(string newData) {

}

void BSTNode::setRight(BSTNode *newRight) {

}

void BSTNode::setLeft(BSTNode *newLeft) {

}

ostream &operator<< (ostream &lhs, BSTNode &rhs) {
  lhs << rhs.getData() << " ";
  return lhs;
}
