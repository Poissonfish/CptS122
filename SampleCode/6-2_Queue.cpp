#include "Queue.h"

bool Queue::enqueue(const string &newPrintJob)
{
	// inserting at the end of the linked list
	Node *pMem = nullptr;
	
	pMem = new Node(newPrintJob);

	bool success = false;

	if (this->mpHead == nullptr)
	{
		// empty queue
		this->mpHead = this->mpTail = pMem;
	}
	else
	{
		// queue is not empty
		this->mpTail->setNextPtr(pMem);
		this->mpTail = pMem;
	}

	success = true;

	return success;
}
