#include "BST.h"

void BST::insert(Data &newData)
{
	insert(this->mpRoot, newData);
}

void BST::insert(Node *& pTree, Data &newData)
{
	// we still have a lot of work to do with this function!
	// we also need to consider whether or not pTree should be
	// ** or something else!

	// base case
	if (pTree == nullptr)
	{
		Node *pMem = new Node(newData); // this invokes the constructor for Node
		pTree = pMem;
	}
	else if (newData < (pTree)->getData()) // left subtree - recursive step
	{
		// we need to work on this statement. Consider:
		// are should we be using double level of indirection?
		// could we solve this problem using references instead?
		insert((pTree)->getLeft(), newData);
	}
	else // means duplicate, or go to right subtree
	{
		insert(pTree->getRight(), newData);
	}
}

void BST::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

void BST::inorderTraversal(Node *pTree)
{
	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeft());
		cout << pTree->getData().getRational().getNumerator () <<
			" / " << pTree->getData().getRational().getDenominator() << endl;
		inorderTraversal(pTree->getRight());
	}
}

void BST::postorderTraversal()
{
	postorderTraversal(this->mpRoot);
}

void BST::postorderTraversal(Node *pTree)
{
	if (pTree != nullptr)
	{
		// recursive steps
		postorderTraversal(pTree->getLeft());
		postorderTraversal(pTree->getRight());
		cout << pTree->getData().getRational().getNumerator() <<
			" / " << pTree->getData().getRational().getDenominator() << endl;
	}
}