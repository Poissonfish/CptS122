#include "BSTNode.h"

BSTNode::BSTNode ()
{
	this -> mData = "";
	this -> mpLeft = nullptr;
	this -> mpRight = nullptr;
}

// constructor
BSTNode::BSTNode (string newData)
{
	this -> mData = newData;
	this -> mpLeft = nullptr;
	this -> mpRight = nullptr;
}

// copy constructor
BSTNode::BSTNode (BSTNode &copy)
{
	// shallow copy
	mData = copy.mData;
	mpLeft = copy.mpLeft;
	mpRight = copy.mpRight;
}

// destructor
BSTNode::~BSTNode ()
{
	// do nothing for now
}

// getters
string BSTNode::getData () const
{
	return mData;
}

BSTNode *& BSTNode::getLeftPtr ()
{
	return mpLeft;
}

BSTNode *& BSTNode::getRightPtr ()
{
	return mpRight;
}

// setters
void BSTNode::setData (string newData)
{
	mData = newData;
}

void BSTNode::setLeftPtr (BSTNode *newLeftPtr)
{
	mpLeft = newLeftPtr;
}

void BSTNode::setRightPtr (BSTNode *newRightPtr)
{
	mpRight = newRightPtr;
}

// overloaded stream insertion operator
ostream & operator<< (ostream &output, BSTNode const &rhs)
{
	output << rhs.getData () << " ";
	return output;
}