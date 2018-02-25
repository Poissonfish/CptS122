#include "Queue.h"

bool Queue::isEmpty() {
  return this->head == nullptr;
}

bool Queue::enqueue(const string &newData) {
  QueueNode *pNew = nullptr;
  pNew = new QueueNode(newData);
  bool suc = false;
  if (this->isEmpty())
    this->head = this->tail = pNew;
  else {
    this->tail->setNextPtr(pNew);
    this->tail = pNew;
  }
  suc = true;
  return suc;
}

string Queue::dequeue() {
  string temp;
  if (this->isEmpty())
    return NULL;
  else {
    QueueNode *pTemp = this->head;
    temp = pTemp->getData();
    this->head = this->head->getNextPtr();
    delete pTemp;
  }
  return temp;
}

void Queue::printQueueRecursive() {
  if (this->isEmpty())
    cout << "The queue is empty!" << endl;
  else {
    QueueNode *pTemp = this->head;
    while (pTemp != nullptr) {
      cout << pTemp << endl;
      pTemp = pTemp->getNextPtr();
    }
  }
}
