#pragma once

#include <iostream>
#include "QueueNode.h"

using std::string;
using std::cout;
using std::endl;

class Queue {

public:
  Queue(bool isExpress);
  Queue(Queue &copy);
  ~Queue();

  QueueNode *getHead() const;
  QueueNode *getTail() const;

  void setHead(QueueNode * &head);
  void setTail(QueueNode * &tail);

  bool isEmpty();
  bool isOneNode();
  bool enqueue(Data * &newData); // Why can't pass const?
  Data *dequeue();
  void destroyQueue();
  void printQueue();

  void iniCustomer();
  void iniService();
  void checkArrival(int &number, int overall);
  void checkOut();
  void updateElapsed();

private:
  QueueNode *pHead;
  QueueNode *pTail;
  bool isExp;
  int counterNew;
  int counterOut;
  int arrivalMax;
  int arrivalMin;
};

int getRdm(int max, int min);
