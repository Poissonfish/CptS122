#include "Node.h"

Node::Node(string data) {
    this->mData = data;
    this->mpLeft = nullptr;
    this->mpRight = nullptr;
}

Node::~Node() {
//    cout << "Node Destructor" << endl;
}

string Node::getData() {
    return this->mData;
}

Node *&Node::getLeft() {
    return this->mpLeft;
}

Node *&Node::getRight() {
    return this->mpRight;
}

void Node::setData(string data) {
    this->mData = data;
}

void Node::setLeft(Node *pLeft) {
    this->mpLeft = pLeft;
}

void Node::setRight(Node *pRight) {
    this->mpRight = pRight;
}

void Node::printData() {
    cout << this->mData << endl;
}
