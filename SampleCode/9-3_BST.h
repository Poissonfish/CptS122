#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BST
{
public:
	BST()
	{
		this->mpRoot = nullptr;
	}

	void insert(Data &newData);
	void inorderTraversal();
	void postorderTraversal();

private:
	Node *mpRoot;
	void insert(Node *& pTree, Data &newData); // will implement recursively!
	void inorderTraversal(Node *pTree);
	void postorderTraversal(Node *pTree);

};