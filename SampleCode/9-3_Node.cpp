#include "Node.h"

Node::Node(Data &newData)
{
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
	this->pData = new Data(newData); // this invokes the COPY constructor for Data
}
Data Node::getData()
{
	return *(this->pData);
}

Node *& Node::getLeft()
{
	return this->mpLeft;
}

Node *& Node::getRight()
{
	return this->mpRight;
}