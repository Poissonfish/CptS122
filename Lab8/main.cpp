#include "BST.h"

int main(void) {
  BST *myTree = new BST();
  myTree -> insertNode("Monkey");
  myTree -> insertNode("Frog");
  myTree -> insertNode("Turtle");
  myTree -> insertNode("Dog");
  myTree -> insertNode("Chicken");
  myTree -> insertNode("Elephant");
  myTree -> insertNode("Zebra");
  myTree -> insertNode("Giraffe");

  cout << "Old tree: ";
  myTree -> inOrderTraversal();
  cout << endl;

  BST *copyTree(myTree);
  cout << "New tree: ";
  copyTree->inOrderTraversal();
  cout << endl;
}
