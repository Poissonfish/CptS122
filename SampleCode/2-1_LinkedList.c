#include "LinkedList.h"

Node *makeNode(Student newStudent) // place the value inside the container
{
	Node *pMem = NULL;

	pMem = (Node *) malloc(sizeof (Node));

	if (pMem != NULL) // space was allocated
	{
		pMem->pNext = NULL;
		pMem->s = newStudent; // we want to make a copy!
	}

	return pMem;
}

int insertAtFront(Node **pList, Student newStudent) // list operation
{
	Node *pMem = NULL;
	int success = 0;

	pMem = makeNode(newStudent);

	if (pMem != NULL) // we allocated space for a Node and initialized it
	{
		// connect the new Node/container to the list
		pMem->pNext = *pList;
		*pList = pMem;
		success = 1;
	}

	return success;
}