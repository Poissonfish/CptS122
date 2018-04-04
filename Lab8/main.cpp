#include "BSTNode.h"
#include "BST.h"

int main (void)
{
	BST myTree;

	myTree.insertNode ("Monkey");
	myTree.insertNode ("Ostrich");
	myTree.insertNode ("Lion");
	myTree.insertNode ("Lizard");
	myTree.insertNode ("Cat");
	myTree.insertNode ("Zebra");

	BST copyTree (myTree);
	copyTree.inOrderTraversal ();
	copyTree.preOrderTraversal ();
	copyTree.postOrderTraversal ();
}
