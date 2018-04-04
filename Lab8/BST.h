#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class BST
{
	public:
		BST ();
		BST (BST &copy);
		~BST ();

		BST & operator= (BST const &rhs);

		BSTNode* copyTree (BSTNode const *currentNode);
		void insertNode (string newData);
		void inOrderTraversal ();
		void preOrderTraversal ();
		void postOrderTraversal ();
		bool isEmpty ();
	
	private:
		BSTNode *mpRoot;

		BSTNode* makeNode (string newData);
		void destroyTree (BSTNode *pTree);
		void insertNode (BSTNode **pTree, string newData);
		void inOrderTraversal (BSTNode *pTree);
		void preOrderTraversal (BSTNode *pTree);
		void postOrderTraversal (BSTNode *pTree);
};

#endif