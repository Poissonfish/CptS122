#ifndef PA8_TRANSACTIONNODE_H
#define PA8_TRANSACTIONNODE_H

#include "Node.h"

class TransactionNode : public Node {
public:
    TransactionNode(string data, int nUnits) : Node(data) {
        this->mUnits = nUnits;
    }
    ~TransactionNode();

    int getUnit();

    void setUnit(int units);

    // print node's value
    void printData();

private:
    int mUnits;
};

#endif //PA8_TRANSACTIONNODE_H
