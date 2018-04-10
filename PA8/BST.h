#ifndef PA8_BST_H
#define PA8_BST_H

#include "TransactionNode.h"

class BST {
public:
    BST();
    ~BST();

    Node *getter();

    void setRoot(Node *root);

    // insert tree given units and call private function
    void insert(string data, int units);
    // inorder traversal and print out the node value
    void inOrderTraversal();
    // return the node with the smallest units
    TransactionNode &findSmallest();
    // return the node with the largest units
    TransactionNode &findLargest();

private:
    Node *mpRoot;
    // private function
    // recursively delete node post order
    void destroyTree(Node *root);
    // recursively insert node by units
    void insert(string data, int units, Node *&root);
    // recursively traversal the tree in order
    void inOrderTraversal(Node *root);
};

#endif //PA8_BST_H
