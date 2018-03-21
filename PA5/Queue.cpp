#include "Queue.h"

Queue::Queue(bool isExpress) {
  this->pHead = this->pTail = nullptr;

  this->counterNew = 0;
  this->counterOut = 0;
  this->isExp = isExpress;
  if (isExpress) {
    this->arrivalMax = 5;
    this->arrivalMin = 1;
  } else {
    this->arrivalMax = 8;
    this->arrivalMin = 3;
  }
}

Queue::Queue(Queue &copy) {
  this->pHead = copy.getHead();
  this->pTail = copy.getTail();
}

Queue::~Queue() {
  delete this->pHead;
  delete this->pTail;
}

QueueNode *Queue::getHead() const {
  return this->pHead;
}

QueueNode *Queue::getTail() const {
  return this->pTail;
}

void Queue::setHead(QueueNode * &head) {
  this->pHead = head;
}

void Queue::setTail(QueueNode * &tail) {
  this->pTail = tail;
}

bool Queue::isEmpty() {
  return (this->getHead()) == nullptr;
}

bool Queue::isOneNode() {
  return (this->getHead() == this->getTail());
}

bool Queue::enqueue(Data * &newData) {
  QueueNode *pNew = new QueueNode(newData);
  bool suc = false;
  if (this->isEmpty())
    this->pHead = this->pTail = pNew;
  else {
    this->pTail->setNextPtr(pNew);
    this->setTail(pNew);
  }
  suc = true;
  return suc;
}

Data *Queue::dequeue() {
  if (this->isEmpty())
    return nullptr;
  // One node in queue
  else if (this->isOneNode()) {
    Data *temp = this->getHead()->getData();
    // delete &(this->pHead);
    this->pHead = this->pTail = nullptr;
    return temp;
  // More than one node in queue
  } else {
    QueueNode *pTemp = this->getHead();
    Data *temp = this->getHead()->getData();
    this->pHead = this->pHead->getNextPtr();
    // delete pTemp;
    return temp;
  }
  return nullptr;
}

void Queue::destroyQueue() {
  while (!isEmpty())
		dequeue();
	if (this->getHead() == nullptr && this->getTail() == nullptr)
		cout << "Deleted all nodes" << endl;
}

void Queue::printQueue() {
  if (this->isEmpty())
    cout << "  The queue is empty!" << endl;
  else {
    QueueNode *pTemp = this->getHead();
    while (pTemp != nullptr) {
      cout << (*pTemp) << endl;
      pTemp = pTemp->getNextPtr();
    }
  }
}

void Queue::iniCustomer() {
  this->counterNew = getRdm(this->arrivalMax, this->arrivalMin);
}

void Queue::iniService() {
  this->counterOut = this->getHead()->getData()->getServiceTime();
}

void Queue::checkArrival(int &number, int overall) {
  // cout << "Arrival in " << this->counterNew << endl;
  if (this->counterNew == 0) {
    Data *customer = new Data(number, getRdm(this->arrivalMax, this->arrivalMin), 0);
    number += 1;
    enqueue(customer);
    if (isExp) {
      cout << "Express : Customer " << customer->getNumber();
      cout << " entered the lane at time : " << overall << endl;
      if (isOneNode())
        iniService();
    } else {
      cout << "Normal  : Customer " << customer->getNumber();
      cout << " entered the lane at time : " << overall << endl;
      if (isOneNode())
        iniService();
    }
    iniCustomer();
  } else
    this->counterNew -= 1;
}

void Queue::checkOut() {
  // cout << "Out in " << this->counterOut << endl;
  if (this->isEmpty())
    return;
  if (this->counterOut == 0) {
    Data *out = dequeue();
    if (isExp) {
      cout << "Express : Customer " << out->getNumber() << " is out ";
      cout << "and has spent " << out->getTotalTime() << " minutes" << endl;
    } else {
      cout << "Normal  : Customer " << out->getNumber() << " is out ";
      cout << "and has spent " << out->getTotalTime() << " minutes" << endl;
    }
    if (!this->isEmpty())
      iniService();
  } else
    this->counterOut -= 1;
}

void Queue::updateElapsed() {
  QueueNode *pTemp = this->getHead();
  while (pTemp != nullptr) {
    pTemp->updateTotalTime(1);
    pTemp = pTemp->getNextPtr();
  }
}

int getRdm(int max, int min) {
  return min + (rand() % (max - min + 1));
}
