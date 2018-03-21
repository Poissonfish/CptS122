#pragma once

#include <iostream>
#include "Data.h"

using std::cout;
using std::endl;
using std::ostream;

class QueueNode {

public:
  QueueNode(Data * &newData);
  QueueNode(QueueNode &copy);
  ~QueueNode();

  Data *getData() const;
  QueueNode *getNextPtr() const;

  void setData(Data * &newData);
  void setNextPtr(QueueNode *const pNext);

  void updateTotalTime(int by);

private:
  // The memory for Data will need to be allocated on the heap as well
  Data *pData;
  QueueNode *pNext;
};

ostream & operator<< (ostream &outstream, const QueueNode &queue);
