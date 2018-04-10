#include "BST.h"

BST::BST() {
    this->mpRoot = nullptr;
}

BST::~BST() {
    this->destroyTree(this->mpRoot);
}

void BST::insert(string data, int units) {
    this->insert(data, units, this->mpRoot);
}

void BST::inOrderTraversal() {
    this->inOrderTraversal(this->mpRoot);
}

TransactionNode &BST::findSmallest() {
    Node *pTemp = this->mpRoot;
    while (pTemp->getLeft() != nullptr)
        pTemp = pTemp->getLeft();
    return *(dynamic_cast<TransactionNode *>(pTemp));
}

TransactionNode &BST::findLargest() {
    Node *pTemp = this->mpRoot;
    while (pTemp->getRight() != nullptr)
        pTemp = pTemp->getRight();
    return *(dynamic_cast<TransactionNode *>(pTemp));
}

// private functions //

void BST::destroyTree(Node *root) {
    if (root != nullptr) {
        destroyTree(root->getLeft());
        destroyTree(root->getRight());
        delete root;
    }
}

void BST::insert(string data, int units, Node *&root) {
    if (root == nullptr)
        root = new TransactionNode(data, units);
    else if (units < (dynamic_cast <TransactionNode *>(root))->getUnit())
        this->insert(data, units, root->getLeft());
     else if (units > (dynamic_cast <TransactionNode *>(root))->getUnit())
        this->insert(data, units, root->getRight());
}

void BST::inOrderTraversal(Node *root) {
    if (root != nullptr) {
        inOrderTraversal(root->getLeft());
        root->printData();
        inOrderTraversal(root->getRight());
    }
}

