#include "Stack.hpp"

Stack::Stack() {
  this->node = nullptr;
  this->size = 0;
}

// deep copy
Stack::Stack(const Stack &copy) {
    int size = copy.getSize();
    Date *arrayDate = new Date[size];
    for (int i = 0; i < size; i ++)
        arrayDate[i] = copy.node[i];
    this->node = arrayDate;
    this->size = size;
}

Stack::~Stack() {
    delete this->node;
    delete &(this->size);
}

int Stack::getSize()const {
    return this->size;
}

bool Stack::isEmpty() {
    return this->size == 0 ? true : false;
}

void Stack::push(Date * &newDate) {
    // Skip the empty entry
    if (!newDate->getDate().compare("0000/00/00"))
        return void();
    Date *arrayDate = new Date[++(this->size)];
    arrayDate[0] = *newDate;
    for (int i = 0; i < this->size - 1; i ++)
    arrayDate[i + 1] = this->node[i];
    this->node = arrayDate;
}

Date *Stack::pop() {
  Date *arrayDate = new Date[--(this->size)];
  Date *popDate = &(this->node[0]);
  for (int i = 0; i < this->size; i ++)
    arrayDate[i] = this->node[i + 1];
  this->node = arrayDate;
  return popDate;
}

Date *Stack::peek() {
    Date *newDate = new Date();
    newDate->setDate("0000/00/00");
    return this->isEmpty() ? newDate : &(this->node[0]);
}

void Stack::printStack() {
    cout << "Time of Absence : " << this->getSize() << endl;
    for (int i = 0; i < this->getSize(); i ++) {
        cout << i + 1 << ". " << this->node[i] << endl;
    }
}

void Stack::removeAtN(int n) {
    int size = this->getSize();
    Date *arrayDate = new Date[size - 1];
    int j = 0;
    for (int i = 0; i < size; i ++) {
        if (i == n)
            continue;
        arrayDate[j ++] = this->node[i];
    }
    this->node = arrayDate;
    this->size = size - 1;
}