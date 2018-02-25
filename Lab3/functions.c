# include "functions.h"

Post *makeNode (int data) {
  Post *pNew = (Post*) malloc(sizeof(Post));
  if (pNew != NULL) {
    pNew->diameter = data;
    pNew->pNext = NULL;
    return pNew;
  }
  return NULL;
}

int isEmpty (Post *stack) {
  return (stack == NULL) ? 1 : 0;
}

int push (Post **pStack, int data) {
  Post *pNew = makeNode(data);
  if (pNew != NULL) {
    pNew->pNext = *pStack;
    *pStack = pNew;
    return 1;
  } else
    return 0;
}

void pop (Post **pStack) {
  Post *pTemp = *pStack;
  if (pStack != NULL) {
    *pStack = (*pStack)->pNext;
    printf("Pop: %d\n", pTemp->diameter);
    free(pTemp);
  }
}

int top (Post *pStack) {
  return pStack->diameter;
}

int peekAndPop (Post **pStack) {
  Post *pTemp = *pStack;
  int value = 0;
  if (pStack != NULL) {
    *pStack = (*pStack)->pNext;
    value = pTemp->diameter;
    printf("Pop: %d\n", value);
    free(pTemp);
  }
  return value;
}

Desk makeDesk (int size) {
  Desk newDesk;
  newDesk.size = size;
  for (int i = size; i > 0; i--)
    push(&(newDesk.post1), i);
  return newDesk;
}

void displayDesk(Desk *desk) {
    int counter = desk->size;
    printf("post1\n");
    printPost(desk->post1, 10);
    printf("post2\n");
    printPost(desk->post2, 10);
    printf("post3\n");
    printPost(desk->post3, 10);
}

void printPost(Post *post, int counter) {
  while(post != NULL) {
    printf("%d\n", post->diameter);
    post = post->pNext;
    counter --;
    printf("remain %d\n", counter);
  }
  for (int i = 0; i < counter; i ++)
    printf("-");
  printf("\n");
}
