# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h> // Mac

typedef struct node {
  int data;
  struct node *pNext;
} Node;

void task1(void);
void task2(void);
char *copyStrToHeap(char *pStr);
void task3(void);
char *copyStrToHeap2(char *pStr);
void task4(void);
Node *Merge (Node *list1, Node *list2, int isDescending);

int main(void) {
  // task1();
  task2();
  task3();
  task4();

}

void task1(void) {
  int n1 = 10,
      n2 = 42,
      list[] = {6,8, 42, 3, 2, 2, -6};
  int *const p1 = &n1; // place be pointed can't be changed
  const int *p2 = &n1; // value can't be changed
  int *p3 = list;

  *p1 = 15; //legal
  p1 = &n2; //not legal, cause you can't change the pointer

  p2 = &n2; //legal
  *p2 = 67; //not legal, cause you cant' modify where the pointer point to

  p3[4] = 67; //legal
  list = &n1; //legal
}


char *copyStrToHeap(char *pStr) {
  int len = strlen(pStr);
  char *newStr = (char *) malloc(sizeof(char) * (len + 1));
  if (newStr == NULL) {
    return NULL;
  } else {
    strncpy(newStr, pStr, len + 1);
    return newStr;
  }
}

void task2(void) {
    char *pt = "abbcc";
    char *newS = copyStrToHeap(pt);
    printf("%s\n", newS);
    int size = strlen(newS);
    printf("size = %d\n", size);
}

char *copyStrToHeap2(char *pStr) {
  int len = strlen(pStr);
  char newStr[len];
  memcpy(newStr, pStr, len + 1);
  return newStr;
}

void task3(void) {
  char *pt = "abbcc";
  char *newS = copyStrToHeap2(pt);
  printf("%s\n", newS);
  int size = strlen(newS);
  printf("size = %d\n", size);
  // I think we can also copy a struct cause we know its required size to allocate.
}

Node *makeNode(int data) {
	// Declaration
  Node *node = NULL;
	// Allocate memeory for the node
  node = (Node *) malloc(sizeof(Node));
	// If allocate memory for node
	if (node != NULL) {
	  node->data = data;
	  node->pNext = NULL;
	}
	return node;
}

int insertFront(Node **list, int data) {
	// Declaration
	int success = 0;
	Node *pNew = makeNode(data);
	if (pNew != NULL) {
		// Not an empty list
		if (*list != NULL) {
			pNew->pNext = *list;
			*list = pNew;
		// An empty list
		} else {
			*list = pNew;
		}
		success = 1;
	} else
		printf("Invalid record\n");
	return success;
}

Node *Merge (Node *list1, Node *list2, int isDescending){
  Node *pNew;
  if (isDescending) {

  } else {

  }
	Node *pTemp = list1;
	while (pTemp->pNext != NULL)
		pTemp = pTemp->pNext;
	pTemp->pNext = list2;
	return list1;
}

void task4() {
  Node *list1 = makeNode(1);
  insertFront(&list1, 3);
  insertFront(&list1, 5);
  insertFront(&list1, 7);
  insertFront(&list1, 9);

  Node *list2 = makeNode(2);
  insertFront(&list2, 4);
  insertFront(&list2, 6);
  insertFront(&list2, 8);
  insertFront(&list2, 0);

  printf("List1 : \n");
  while (list1 != NULL) {
    printf("%d\n", list1->data);
    list1 =list1->pNext;
  }
  printf("List2 : \n");
  while (list2 != NULL) {
    printf("%d\n", list2->data);
    list2 =list2->pNext;
  }
  Node *pMerge = Merge(list1, list2, 1);
}
