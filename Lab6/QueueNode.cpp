#include "QueueNode.h"

QueueNode::QueueNode(const string &newData) {
  this->data = newData;
}

QueueNode::QueueNode(const QueueNode &newNode) {
  this->data = newNode.getData();
}

QueueNode::~QueueNode() {
  delete &(this->data);
}

string QueueNode::getData() const {
  return this->data;
}

QueueNode *QueueNode::getNextPtr() const {
  return this->pNext;
}

void QueueNode::setData(const string &newData) {
  this->data = newData;
}

void QueueNode::setNextPtr(QueueNode *const pNext) {
  this->pNext = pNext;
}
