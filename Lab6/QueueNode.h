#pragma once

#include <iostream>

using std::string;
using std::ostream;

class QueueNode {
public:
  QueueNode(const string &newData);
  QueueNode(const QueueNode &newNode);
  ~QueueNode();

  string getData() const;
  QueueNode *getNextPtr() const;

  void setData(const string &newData);
  void setNextPtr(QueueNode *const pNext);

private:
  string data;
  QueueNode *pNext;
};

std::ostream &operator<< (ostream &lhs, const QueueNode &rhs) {
  lhs << rhs.getData();
  return lhs;
}
