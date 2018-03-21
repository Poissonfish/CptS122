#pragma once

#include "ListNode.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::fstream;

class List {
public:
    List();
    List(const List &copyList);
    ~List();
    void destroyList(ListNode *pMem);

    // Getters
    ListNode *getHead() const;
    ListNode *getEnd() const;

    // Setters
    void setHead(ListNode *newHead);

    // check if the list is empty
    bool isEmpty() const;
    // insert node at front
    bool insertAtFront(ListNode *newNode);
    // insert node at end
    void insertAtEnd(ListNode *newNode);
    // delete node at front
    bool deleteAtFront();
    // delete node at end
    void deleteAtEnd();

private:
  ListNode *pHead;
};

fstream & operator>> (fstream &lhs, List &rhs);
ostream & operator<< (ostream &lhs, const List &rhs);
fstream & operator<< (fstream &lhs, const List &rhs);
