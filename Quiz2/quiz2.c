#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
  int data;
  struct node *pNext;
} Node;
Node *makeNode (int data);

void printNode (Node *node);
int insertAtFront (Node **node, int data);
int deleteAtPositionN (Node **pHead, int n, int *pData);

int main (void) {
  int data = -1;
  // Create a linked node
  Node *node = makeNode(1005);
  insertAtFront(&node, 1004);
  insertAtFront(&node, 1003);
  insertAtFront(&node, 1002);
  insertAtFront(&node, 1001);
  insertAtFront(&node, 1000);
  // Inspect the linked node
  printNode (node);
  // Delete one node
  deleteAtPositionN(&node, 6, &data);
  printf("you deleted : %d\n", data);
  // Inspect the linked node after removal
  printNode (node);
  printf("done\n");
}

void printNode (Node *node) {
  if (node != NULL) {
    printf("Node value : %d\n", node->data);
    printNode (node->pNext);
  }
}


Node *makeNode (int data) {
  Node *newNode = NULL;
  newNode = (Node*) malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->data = data;
    newNode->pNext = NULL;
  }
  return newNode;
}


int insertAtFront (Node **node, int data) {
  Node *newNode = makeNode(data);
  int success = 0;
  if (newNode != NULL) {
    newNode->pNext = *node;
    *node = newNode;
    success = 1;
  }
  return success;
}

int deleteAtPositionN (Node **pHead, int n, int *pData) {
  Node *pTemp = NULL,
       *pPrev = NULL;
  pTemp = *pHead;
  if (n == 1) {
    *pHead = (*pHead)->pNext;
  } else {
    for (int i = n ; i > 1; i --) {
      pPrev = pTemp;
      pTemp = pTemp->pNext;
    }
    pPrev->pNext = pTemp->pNext;
  }
  *pData = pTemp->data;
  free(pTemp);
  return 1;
}
