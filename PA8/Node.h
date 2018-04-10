#ifndef PA8_NODE_H
#define PA8_NODE_H

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Node {
public:
    Node(string data);
    virtual ~Node();

    string getData();
    Node *&getLeft();
    Node *&getRight();

    void setData(string data);
    void setLeft(Node *pLeft);
    void setRight(Node *pRight);

    virtual void printData() = 0;

protected:
    string mData;
    Node *mpLeft;
    Node *mpRight;
};

#endif //PA8_NODE_H
