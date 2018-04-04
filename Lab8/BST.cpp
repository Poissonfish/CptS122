#include "BST.h"

// NOTE: we would not be able to access
//		 mData, mpLeft, and mpRight if BST was
//		 not a friend of BSTNode!
//       comment out the friend declaration in BSTNode.h
//       on line 19 and watch which errors pop up!

// constructor
BST::BST ()
{
	this -> mpRoot = nullptr;
}

// copy constructor
BST::BST (BST &copy)
{
	// call the copyTree helper function
	this -> mpRoot = copyTree (copy.mpRoot);
}

//destructor
BST::~BST ()
{
	// call the destroyTree function
	destroyTree (mpRoot);
}

// overloaded assignment operator
BST & BST::operator= (BST const &rhs)
{
	// call the copyTree helper function
	this -> mpRoot = copyTree (rhs.mpRoot);

	return (*this);
}

// recursively deep copies a BST
// notice the pre-order traversal!
BSTNode* BST::copyTree (BSTNode const *currentNode)
{
	// base case: if the current node is null
	// return null
	if (currentNode == nullptr)
	{
		return nullptr;
	}

	// dynamically allocate a new node to store the new node
	BSTNode *newNode = new BSTNode ();

	// copy the currentNode's data
	newNode -> setData (currentNode -> mData);

	// recursive calls to the left and right
	newNode -> mpLeft = copyTree (currentNode -> mpLeft);
	newNode -> mpRight = copyTree (currentNode -> mpRight);

	return newNode;
}

// the public insertNode function will
// call the private insertNode function in
// order to hide the root and keep it private
void BST::insertNode (string newData)
{
	insertNode (&mpRoot, newData);
}

void BST::inOrderTraversal ()
{
	// call the private inOrderTraversal function
	// by passing in the root
	inOrderTraversal (mpRoot);
	cout << endl;
}

void BST::preOrderTraversal ()
{
	// call the private preOrderTraversal function
	// by passing in the root
	preOrderTraversal (mpRoot);
	cout << endl;
}

void BST::postOrderTraversal ()
{
	// call the private postOrderTraversal function
	// by passing in the root
	postOrderTraversal (mpRoot);
	cout << endl;
}

bool BST::isEmpty ()
{
	bool success = false;

	// if the root is null, the tree is empty
	if (mpRoot == nullptr)
	{
		success = true;
	}

	return success;
}

// ******************** private member functions below ********************

BSTNode* BST::makeNode (string newData)
{
	BSTNode *newNode = new BSTNode (newData);

	return newNode;
}

void BST::destroyTree (BSTNode *pTree)
{
	// base case: the current node is not null
	if (pTree != nullptr)
	{
		// go all the way to the left
		destroyTree (pTree -> mpLeft);

		// go all the way to the right
		destroyTree (pTree -> mpRight);

		// print out the node's data before we delete it
		cout << "Deleting node with value: " << pTree -> getData () << endl;

		// delete the node
		delete pTree;
	}
}

void BST::insertNode (BSTNode **pTree, string newData)
{
	// base case: pTree is null
	if (*pTree == nullptr)
	{
		// make the newNode with the makeNode function
		BSTNode *newNode = makeNode (newData);

		// set the current node to the newNode
		// since we passed in pTree as a reference to a pointer,
		// we don't need to dereference pTree
		// all changes to pTree will be retained through the reference
		*pTree = newNode;
	}
	else if (newData > ((*pTree) -> mData))
	{
		// the data is greater then the current node's data
		// so we go right
		// since the getRightPtr () returns a reference to the node,
		// all changes to the right ptr will be retained
		insertNode (&(*pTree) -> getRightPtr (), newData);
	}
	else if (newData < ((*pTree) -> mData))
	{
		// the data is less than the current node's data
		// so we go left
		// since the getLeftPtr () returns a reference to the node,
		// all changes to the right ptr will be retained
		insertNode (&(*pTree) -> getLeftPtr (), newData);
	}
	else
	{
		// if all other cases fail, the newData must be a duplicate
		cout << newData << " is a duplicate value!" << endl;
	}
}

void BST::inOrderTraversal (BSTNode *pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal (pTree -> getLeftPtr ());

		// dereference pTree here to call the
		// overloaded stream insertion operator
		cout << *pTree;

		// if we didn't dereference pTree,
		// we would not call the overloaded stream insertion operator
		// because the rhs is a pointer to a BSTNode, NOT a BSTNode
		// this will just print out the address of pTree
		//cout << pTree;

		inOrderTraversal (pTree -> getRightPtr ());
	}
}

void BST::preOrderTraversal (BSTNode *pTree)
{
	if (pTree != nullptr)
	{
		cout << *pTree;
		preOrderTraversal (pTree -> getLeftPtr ());
		preOrderTraversal (pTree -> getRightPtr ());
	}
}

void BST::postOrderTraversal (BSTNode *pTree)
{
	if (pTree != nullptr)
	{
		postOrderTraversal (pTree -> getLeftPtr ());
		postOrderTraversal (pTree -> getRightPtr ());
		cout << *pTree;
	}
}
