#include "List.hpp"

List::List() {
  this->pHead = nullptr;
}

List::List(const List &copyList) {
  //a pointer to track where we are at in this list
	ListNode *cur1 = this->pHead;
  //a pointer to track where we are at in the list that is being copied
	ListNode *cur2 = copyList.getHead();
  //copy the data over to the first node
  cur1 = new ListNode(
    cur2->getRecord(),
    cur2->getID(),
    cur2->getName(),
    cur2->getEmail(),
    cur2->getUnits(),
    cur2->getProgram(),
    cur2->getLevel());
  //advance to the next node in the list we are copying
	cur2 = cur2->getNext();

//while not at the end of the list that is being copied
	while (cur2 != nullptr) {
        //add a NEW NODE (hence the deep copy) to this list with the copied data
        cur1->setNext(new ListNode(
        cur2->getRecord(),
        cur2->getID(),
        cur2->getName(),
        cur2->getEmail(),
        cur2->getUnits(),
        cur2->getProgram(),
        cur2->getLevel()));
		//advance through each list
		cur1 = cur1->getNext();
		cur2 = cur2->getNext();
	}
}

List::~List() {
    this->destroyList(this->getHead());
}

void List::destroyList(ListNode *pMem) {
    if (pMem != nullptr) {
        destroyList(pMem->getNext());
        delete pMem;    // delete from the back of list to the front!
    }
}

ListNode *List::getHead() const {
  return this->pHead;
}

ListNode *List::getEnd() const {
  ListNode *pTemp = this->getHead();
  if (this->isEmpty())
    return nullptr;
  else {
    while (pTemp->getNext() != nullptr)
      pTemp = pTemp->getNext();
    return pTemp;
  }
}

void List::setHead(ListNode *newHead) {
  this->pHead = newHead;
}

bool List::isEmpty() const {
    return this->getHead() == nullptr;
}

bool List::insertAtFront(ListNode *newNode) {
  if (newNode == nullptr)
    return false;
  else {
    newNode->setNext(this->pHead);
    this->setHead(newNode);
  }
  return true;
}

void List::insertAtEnd(ListNode *newNode) {
  ListNode *pCur = this->getHead();
  if (this->isEmpty())
    this->setHead(newNode);
  else {
    while (pCur->getNext() != nullptr)
      pCur = pCur->getNext();
    pCur->setNext(newNode);
  }
}

bool List::deleteAtFront() {
  ListNode *delNode = this->pHead;
  if (delNode != nullptr) {
    this->setHead(this->pHead->getNext());
    delete delNode;
    return true;
  } else
    return false;
}

void List::deleteAtEnd() {
  if (!this->isEmpty()) {
    ListNode *pCur = this->getHead();
    ListNode *pPrev = this->getHead();
    // Find the end node
    while (pCur->getNext() != nullptr) {
      pPrev = pCur;
      pCur = pCur->getNext();
    }
    // If contains more than one node
    if (pCur != this->pHead) {
      delete pCur;
      pPrev->setNext(nullptr);
    // If only one node
    } else {
      delete pCur;
      this->setHead(nullptr);
    }
  }
}

fstream & operator>> (fstream &lhs, List &rhs) {
    string strTemp;
    List *newList = new List();
    // Skip the header
    getline(lhs, strTemp);
    // Import record until hitting the end
    while (!lhs.eof()) {
        ListNode *newNode = new ListNode();
        lhs >> *newNode;
        newList->insertAtFront(newNode);
    }
    // Somehow there's an extra empty line in the file
    rhs = *(newList);
    if (rhs.getHead()->getRecord() == -1)
        rhs.deleteAtFront();
    return lhs;
}

ostream & operator<< (ostream &lhs, const List &rhs) {
    ListNode *pCur = rhs.getHead();
    while (pCur != nullptr) {
        cout << *pCur << endl;
        pCur = pCur->getNext();
    }
    return lhs;
}

fstream & operator<< (fstream &lhs, const List &rhs) {
    ListNode *pCur = rhs.getHead();
    while (pCur != nullptr) {
        lhs << *pCur << endl;
        pCur = pCur->getNext();
    }
    return lhs;
}
