#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

// this is a forward declaration
class BST; // it lets the compiler know a BST class exists

class BSTNode
{
	// this allows the BST class to access
	// the private data members of BSTNode
	friend class BST;

	public:
		BSTNode ();
		BSTNode (string newData);
		BSTNode (BSTNode &copy);
		~BSTNode ();

		// getters
		string getData () const;
		BSTNode *& getLeftPtr ();
		BSTNode *& getRightPtr ();

		// setters
		void setData (string newData);
		void setLeftPtr (BSTNode *newLeftPtr);
		void setRightPtr (BSTNode *newRightPtr);

	private:
		string mData;
		BSTNode *mpLeft;
		BSTNode *mpRight;

};

// overloaded stream insertion operator
ostream & operator<< (ostream &output, BSTNode const &rhs);

#endif