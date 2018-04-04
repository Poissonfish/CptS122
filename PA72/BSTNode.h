//
// Created by James Chen on 4/4/18.
//

#ifndef CPTS_122_BSTNODE_H
#define CPTS_122_BSTNODE_H

template <class T, class U>
class BSTNode {
public:
    BSTNode(T key, U value);

    // getter
    BSTNode *getLeft();
    BSTNode *getRight();
    T getKey();
    U getVal();
    // setter
    void setLeft(BSTNode *pLeft);
    void setRight(BSTNode *pRight);
    void setKey(T key);
    void setVal(U val);

private :
    BSTNode *pLeft;
    BSTNode *pRight;
    T key;
    U value;
};


#endif //CPTS_122_BSTNODE_H
