#include "Stack.h"

char * reverseString(char *pStr)
{
	Stack s = { NULL }; // this is what caused the program
	                       // to crash, we need to set our
	                       // top pointer to NULL!!!!
	int index = 0;
	Data d;

	// "cat" --> "tac"

	for (; pStr[index] != '\0'; ++index)
	{
		// s.push(pStr[index]);
		d.letter = pStr[index];
		push(&s, d);
	}

	for (index = 0; !isEmpty(s); ++index)
	{
		d = pop(&s);
		pStr[index] = d.letter;
	}

	return pStr;
}

int isEmpty(Stack s)
{
	int returnValue = 0;

	if (s.pTop == NULL)
	{
		returnValue = 1;
	}

	return returnValue;
}

int push(Stack *pStack, Data newData)
{
	// insert at front
	Node *pMem = NULL;
	int success = 0;

	pMem = (Node *)malloc(sizeof(Node)); // ~5 bytes
	if (pMem != NULL)
	{
		success = 1;
		pMem->pNext = NULL;
		pMem->myData = newData;

		// insert
		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}

	return success;
}

// stack must not be empty
Data pop(Stack *pStack)
{
	Data returnValue = {'\0'};
	Node *pTemp = NULL;

	returnValue = pStack->pTop->myData;
	pTemp = pStack->pTop;
	pStack->pTop = pStack->pTop->pNext;
	free(pTemp);

	return returnValue;
}