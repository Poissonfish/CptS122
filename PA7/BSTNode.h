#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <class T, class U>
class BSTNode {

public:
    BSTNode(T key, U value);

    // getter
    T getKey();
    U getVal();
    BSTNode *&getLeft();
    BSTNode *&getRight();
    BSTNode *getPtLeft();
    BSTNode *getPtRight();
    // setter
    void setKey(T key);
    void setVal(U val);
    void setLeft(BSTNode *pLeft);
    void setRight(BSTNode *pRight);

private :
    T key;
    U value;
    BSTNode *pLeft;
    BSTNode *pRight;
};

template <class T, class U>
BSTNode<T, U>::BSTNode(T key, U value) {
	this->key = key;
	this->value = value;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}

template <class T, class U>
T BSTNode<T, U>::getKey() {
	return this->key;
};

template <class T, class U>
U BSTNode<T, U>::getVal() {
	return this->value;
};

template <class T, class U>
BSTNode<T, U> *&BSTNode<T, U>::getLeft() {
	return this->pLeft;
};

template <class T, class U>
BSTNode<T, U> *&BSTNode<T, U>::getRight() {
	return this->pRight;
};

template <class T, class U>
BSTNode<T, U> *BSTNode<T, U>::getPtLeft() {
	return this->pLeft;
};

template <class T, class U>
BSTNode<T, U> *BSTNode<T, U>::getPtRight() {
	return this->pRight;
};

template <class T, class U>
void BSTNode<T, U>::setKey(T key) {
	this->key = key;
};

template <class T, class U>
void BSTNode<T, U>::setVal(U value) {
	this->value = value;
};

template <class T, class U>
void BSTNode<T, U>::setLeft(BSTNode *pLeft) {
	this->pLeft = pLeft;
};

template <class T, class U>
void BSTNode<T, U>::setRight(BSTNode *pRight) {
	this->pLeft = pRight;
};