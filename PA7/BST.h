#pragma once

#include "BSTNode.h"

#include <sstream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::stringstream;

template <class T, class U>
class BST {
public:
    BST (string filename);
    ~BST ();
	
	// Traversal the tree in order
    void print ();
	// Search for key and return the value if a node founded
    void search(T key);
	// Translate sentence from english to Morse code in file
    void translate(string filename);

private:
    BSTNode<T, U> *pRoot;

    BSTNode<T, U> *makeNode (T key, U value);
	// Insert node based on the key
	void insertNode (BSTNode<T, U> **pRoot, T key, U value);
	// Print node value in order in the tree
	void inOrderTraversal (BSTNode<T, U> *pTree);
	// Return node value given the key
    void getValue(BSTNode<T, U> *pTree, T key);
	// Destroy the tree recursively
    void destroyTree (BSTNode<T, U> *pTree);
};

template <class T, class U>
BST<T, U>::BST(string filename) {
	this->pRoot = nullptr;
	// open target file
	ifstream fileMap(filename);
	string strTemp;
	// fetch information
	while (getline(fileMap, strTemp)) {
		const T key = strTemp[0];
		const U value = strTemp.substr(2, strTemp.length() - 2);
		// build tree
		this->insertNode(&(this->pRoot), key, value);
	}
	// close
	fileMap.close();
};

template <class T, class U>
BST<T, U>::~BST() {
	destroyTree(this->pRoot);
}

template <class T, class U>
void BST<T, U>::print() {
	inOrderTraversal(this->pRoot);
	cout << endl;
};

template <class T, class U>
void BST<T, U>::search(T key) {
	getValue(this->pRoot, key);
}

template <class T, class U>
void BST<T, U>::translate(string filename) {
	cout << "Print tree : " << endl;
	this->print();
	ifstream fileConvert(filename);
	string strTemp;
	cout << "Translation result : ";
	while (getline(fileConvert, strTemp)) {
		cout << endl;
		for (char c : strTemp) {
			char key = toupper(c);
			if (key == '\n')
				break;
			else if (isspace(key))
				cout << "  ";
			else
				this->search(key);
		}
	}
	cout << ".-.-.-" << endl;
	fileConvert.close();
};

// private
template <class T, class U>
BSTNode<T, U> *BST<T, U>::makeNode(T key, U value) {
	BSTNode<T, U> *newNode = new BSTNode<T, U>(key, value);
	return newNode;
};

template <class T, class U>
void BST<T, U>::insertNode(BSTNode<T, U> **pRoot, T key, U value) {
	if (*pRoot == nullptr)
		*pRoot = makeNode(key, value);
	else if (((*pRoot)->getKey()) > key)
		insertNode(&(*pRoot)->getLeft(), key, value);
	else if (((*pRoot)->getKey()) < key)
		insertNode(&(*pRoot)->getRight(), key, value);
};

template <class T, class U>
void BST<T, U>::inOrderTraversal(BSTNode<T, U> *pTree) {
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeft());
		cout << pTree->getKey() << "-";
		inOrderTraversal(pTree->getRight());
	}
};

template <class T, class U>
void BST<T, U>::getValue(BSTNode<T, U> *pTree, T key) {
	if (pTree != nullptr) {
		if (pTree->getKey() == key)
			cout << pTree->getVal() << " ";
		else if (pTree->getKey() > key)
			getValue(pTree->getLeft(), key);
		else if (pTree->getKey() < key)
			getValue(pTree->getRight(), key);
	}
}

template <class T, class U>
void BST<T, U>::destroyTree(BSTNode<T, U> *pTree) {
	if (pTree != nullptr) {
		destroyTree(pTree->getPtLeft());
		destroyTree(pTree->getPtRight());
		delete pTree;
	}
}