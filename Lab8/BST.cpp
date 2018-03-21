#include "BST.h"

BST::BST() {
  this->mpRoot = nullptr;
}

// Deep copy (preorder)
BST::BST(BST &copy) {
  this->mpRoot = nullptr;
  copyTreeHelper(copy.mpRoot);
}

BST::~BST() {
  destroyTreeHelper(this->mpRoot);
}

// ====== public functions =======

void BST::insertNode(string newData) {
  insertNode(this->mpRoot, newData);
}

void BST::inOrderTraversal() {
  inOrderTraversal(this->mpRoot);
}

void BST::preOrderTraversal() {
  preOrderTraversal(this->mpRoot);
}

void BST::postOrderTraversal() {
  postOrderTraversal(this->mpRoot);
}

bool BST::isEmpty() {
  return (this->mpRoot == nullptr);
}

// ======= private functions =======

BSTNode *BST::copyTreeHelper(BSTNode *&currentNode) {
  if (currentNode != nullptr) {
    insertNode(currentNode->getData());

  }
}

void BST::destroyTreeHelper(BSTNode *currentNode) {
  if (currentNode != nullptr) {
    destroyTreeHelper(currentNode -> getLeft());
    destroyTreeHelper(currentNode -> getRight());
    delete currentNode;
  }
}

void BST::insertNode(BSTNode *&currentNode, string newData) {
  // base case
  if (currentNode == nullptr) {
      // Insert it
      currentNode = new BSTNode(newData);
      return;
  }

  // newData is greater
  if (newData < currentNode->getData()) {
    // traverse left
    insertNode(currentNode->getLeft(), newData);
  // newData is less
  } else if (newData > currentNode->getData()) {
    // traverse right
    insertNode(currentNode->getRight(), newData);
  // newData is equal
  } else {
    // do nothing
  }
}

// In, Left->Process->Right, dot below
void BST::inOrderTraversal(BSTNode *currentNode) {
  // base case
  if (currentNode != nullptr) {
    inOrderTraversal(currentNode->getLeft());
    cout << *currentNode;
    inOrderTraversal(currentNode->getRight());
  }
}

// Pre, Process->Left->Right,  dot to the left: insert node
void BST::preOrderTraversal(BSTNode *currentNode) {
  // base case
  if (currentNode != nullptr) {
    cout << *currentNode;
    inOrderTraversal(currentNode->getLeft());
    inOrderTraversal(currentNode->getRight());
  }
}

// Post, Left->Right->Process, dot to the right: delete node
void BST::postOrderTraversal(BSTNode *currentNode) {
  // base case
  if (currentNode != nullptr) {
    inOrderTraversal(currentNode->getLeft());
    inOrderTraversal(currentNode->getRight());
    cout << *currentNode;
  }
}
