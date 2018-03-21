#include "List.h"

// default constructor; will always set mpHead to NULL or nullptr
List::List()
{
	mpHead = nullptr;
}

// copy constructor - implicitly invoked copying a List object during construction of
// another List object, or when a List object is passed-by-value - must perform a deep copy,
// which means create new memory for each node copied!
List::List(const List &copyList)
{
	//DYNAMICALLY ALLOCATE A NEW CHUNK OF MEMORY (hence the deep copy) for the first node of our new list
	mpHead = new ListNode;

	ListNode *cur1 = mpHead; //a pointer to track where we are at in this list
	ListNode *cur2 = copyList.getHeadPtr(); //a pointer to track where we are at in the list that is being copied

	cur1->setData(cur2->getData()); //copy the data over to the first node
	cur2 = cur2->getNextPtr(); //advance to the next node in the list we are copying

	while (cur2 != nullptr) //while not at the end of the list that is being copied
	{
		int data = cur2->getData(); //get the data to be copied over
		cur1->setNextPtr(new ListNode(data)); //add a NEW NODE (hence the deep copy) to this list with the copied data

		//advance through each list
		cur1 = cur1->getNextPtr();
		cur2 = cur2->getNextPtr();
	}
}

List::~List()                   // destructor - implicitly invoked when a List object leaves scope
{
	cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}

// this function must allocate new memory for each of the nodes in rhs to construct "this" object
List & List::operator= (const List &rhs) // overloaded assignment operator - must perform a deep copy
{
	// you must use a loop, which visits each of the nodes in List rhs, and assign the data to the new nodes
	// How to use new operator? ListNode *pMem = new ListNode; new is similar to the results of using malloc ()

	// fill in your code here!

	//DYNAMICALLY ALLOCATE A NEW CHUNK OF MEMORY (hence the deep copy) for the first node of our new list
	mpHead = new ListNode;

	ListNode *cur1 = mpHead; //a pointer to track where we are at in this list
	ListNode *cur2 = rhs.getHeadPtr(); //a pointer to track where we are at in the list that is being copied

	cur1->setData(cur2->getData()); //copy the data over to the first node
	cur2 = cur2->getNextPtr(); //advance to the next node in the list we are copying

	while (cur2 != nullptr) //while not at the end of the list that is being copied
	{
		int data = cur2->getData(); //get the data to be copied over
		cur1->setNextPtr(new ListNode(data)); //add a NEW NODE (hence the deep copy) to this list with the copied data

											  //advance through each list
		cur1 = cur1->getNextPtr();
		cur2 = cur2->getNextPtr();
	}

	return (*this);
}

// getter
ListNode * List::getHeadPtr() const     // returns a copy of the address stored in mpHead
{
	return mpHead;
}

// setter
void List::setHeadPtr(ListNode * const pNewHead) // modifies mpHead
{
	mpHead = pNewHead;
}

// This function creates a new ListNode on the heap, and uses the ListNode constructor to initialize the node!
bool List::insertAtFront(const int newData)     // inserts newData at the beginning or front of the list
{
	ListNode *pMem = makeNode(newData);
	bool success = false;                   // C++ has built in bool types - false, true

	if (pMem != nullptr)
	{
		success = true; // allocated memory successfully
		// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

// insert newData in ascending order
bool List::insertInOrder(const int newData)
{
	bool success = false;

	// fill in your code here!
	ListNode *insertMe = new ListNode(newData);
	ListNode *pPrev = nullptr;
	ListNode *pCur = mpHead;

	if (pCur == nullptr) // empty list
	{
		mpHead = insertMe;
		success = true;
	}
	else
	{
		//advance through list
		while (pCur != nullptr && newData > pCur->getData())
		{
			pPrev = pCur;
			pCur = pCur->getNextPtr();
		}

		if (pCur == nullptr) //if inserting at end
		{
			pPrev->setNextPtr(insertMe);
			success = true;
		}
		else if (pPrev != nullptr)//if inserting in middle
		{
			insertMe->setNextPtr(pCur);
			pPrev->setNextPtr(insertMe);
			success = true;
		}
		else //insert at front
		{
			insertMe->setNextPtr(mpHead);
			mpHead = insertMe;
			success = true;
		}

	}
	return success;
}

// inserts newData at the end of the list
bool List::insertAtEnd(const int newData)
{
	bool success = false;

	// fill in your code here!

	ListNode *insertMe = new ListNode(newData);
	ListNode *pCur = mpHead;

	if (pCur == nullptr)// empty list
	{
		mpHead = insertMe;
	}
	else
	{
		while (pCur->getNextPtr() != nullptr) //scan until at last node
		{
			pCur = pCur->getNextPtr();
		}

		//insert
		pCur->setNextPtr(insertMe);
	}

	return success;
}

// determines if the list is empty;
// returns true if the list is empty; false otherwise
bool List::isEmpty()
{
	return (mpHead == nullptr);
}

// deletes the node at the front of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtFront()
{
	int data = 0;

	// fill in your code here! use the delete operator!
	ListNode *deleteMe = mpHead;
	if (mpHead != nullptr)
	{
		data = mpHead->getData();
		mpHead = mpHead->getNextPtr();
		delete deleteMe;
	}

	return data;
}

// deletes the node with data == searchValue;
// returns true if the value was found; false otherwise
// precondition: list must not be empty
bool List::deleteNode(const int searchValue)
{
	bool success = false;

	// fill in your code here! use the delete operator!
	ListNode *pPrev = nullptr;
	ListNode *pCur = mpHead;
	if (mpHead != nullptr) //if not empty
	{
		while (pCur != nullptr && pCur->getData() != searchValue) //perform search
		{
			pPrev = pCur;
			pCur = pCur->getNextPtr();
		}
		if (pCur != nullptr) //if value was found
		{
			if (pPrev != nullptr) //delete in middle or end
			{
				//delete
				pPrev->setNextPtr(pCur->getNextPtr());
				delete pCur;
				success = true;
			}
			else //delete front node
			{
				mpHead = mpHead->getNextPtr();
				delete pCur;
				success = true;
			}
		}
	}

	return success;
}

// deletes the node at the end of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtEnd()
{
	int data = 0;

	// fill in your code here! use the delete operator!
	if (mpHead != nullptr)
	{
		ListNode *pCur = mpHead;
		ListNode *pPrev = mpHead;
		while (pCur->getNextPtr() != nullptr)
		{
			pPrev = pCur;
			pCur = pCur->getNextPtr();
		}
		if (pCur != mpHead)
		{
			data = pCur->getData();
			delete pCur;
			pPrev->setNextPtr(nullptr);
		}
		else //only one node in list
		{
			data = pCur->getData();
			delete pCur;
			mpHead = nullptr;
		}
	}


	return data;
}

// visits each node, print the node's data
void List::printList()
{
	ListNode *pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}
}

int List::computeMax()
{
	int highScore = 0;

	ListNode *pCur = mpHead;
	while (pCur != nullptr)
	{
		if (pCur->getData() > highScore)
			highScore = pCur->getData();
		pCur = pCur->getNextPtr();
	}

	return highScore;
}

int List::computeMin()
{
	int lowScore = mpHead->getData();

	ListNode *pCur = mpHead->getNextPtr();
	while (pCur != nullptr)
	{
		if (pCur->getData() < lowScore)
			lowScore = pCur->getData();
		pCur = pCur->getNextPtr();
	}

	return lowScore;
}

int List::computeMean()
{
	int cumalitiveScore = 0;
	int numberOfNodes = 0;

	ListNode *pCur = mpHead;
	while (pCur != nullptr)
	{
			cumalitiveScore += pCur->getData();
			numberOfNodes++;
			pCur = pCur->getNextPtr();
	}

	return cumalitiveScore / numberOfNodes;
}


//////////// private member functions! //////////////

// allocates memory for a Listnode; initializes the memory with newData
ListNode * List::makeNode(const int newData)    // will only call within insert functions
{
	ListNode *pMem = new ListNode(newData);  // ListNode constructor is invoked!

	return pMem;
}

// we created this function so that we could use recursion to delete the nodes!
void List::destroyListHelper(ListNode * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}

// deletes each node to free memory; will call in the destructor
void List::destroyList()
{
	destroyListHelper(mpHead);
}

ostream & operator<< (ostream &output, const List &rhs)
{
	ListNode *pCur = rhs.getHeadPtr();

	while (pCur != nullptr)
	{
		output << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}

	return output;
}
