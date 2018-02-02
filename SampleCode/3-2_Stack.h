#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char letter;
} Data;

typedef struct node
{
	Data myData;
	struct node *pNext;
} Node;

typedef struct stack
{
	Node *pTop;
} Stack;

char * reverseString(char *pStr);
int isEmpty(Stack s);
int push(Stack *pStack, Data newData);
Data pop(Stack *pStack);

#endif
