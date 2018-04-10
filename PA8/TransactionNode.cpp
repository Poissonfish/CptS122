#include "TransactionNode.h"

TransactionNode::~TransactionNode() {
//    cout << "Transaction Destructor" << endl;
}

int TransactionNode::getUnit() {
    return this->mUnits;
}

void TransactionNode::setUnit(int units) {
    this->mUnits = units;
}

void TransactionNode::printData() {
    cout << "<" << this->getData() << ">";
}
