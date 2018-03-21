#include "QueueNode.h"

QueueNode::QueueNode(Data * &newData) {
  Data *data = new Data(newData->getNumber(),
                newData->getServiceTime(),
                newData->getTotalTime());
  this->pData = data;
  this->pNext = nullptr;
}

QueueNode::QueueNode(QueueNode &copy) {
  Data *data = new Data(copy.pData->getNumber(),
                copy.pData->getServiceTime(),
                copy.pData->getTotalTime());
  this->pData = data;
  this->pNext = copy.getNextPtr();
}

QueueNode::~QueueNode() {
  delete this->pData;
  delete this->pNext;
}

Data *QueueNode::getData() const {
  return this->pData;
}

QueueNode *QueueNode::getNextPtr() const {
  return this->pNext;
}

void QueueNode::setData(Data * &newData) {
  this->pData = newData;
}

void QueueNode::setNextPtr(QueueNode *const pNext) {
  this->pNext = pNext;
}

void QueueNode::updateTotalTime(int by) {
  int Time = this->pData->getTotalTime() + by;
  this->pData->setTotalTime(Time);
}

ostream & operator<< (ostream &outstream, const QueueNode &queue) {
  outstream << "  Customer Number : " << queue.getData()->getNumber() << "\t";
  outstream << "Service Time : " << queue.getData()->getServiceTime() << "\t";
  outstream << "Total Time : " << queue.getData()->getTotalTime();
  return outstream;
}
