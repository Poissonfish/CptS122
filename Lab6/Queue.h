#pragma once

#include <iostream>
#include "QueueNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Queue {

public:
  bool isEmpty();
  bool enqueue(const string &newData);
  string dequeue();
  void printQueueRecursive();

private:
  QueueNode *head;
  QueueNode *tail;
};
