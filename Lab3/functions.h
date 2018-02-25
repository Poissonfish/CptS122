
#ifndef functions_h
#define functions_h

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h> // Mac


typedef struct post {
  int diameter;
  struct post *pNext;
} Post;

typedef struct desk {
  Post *post1;
  Post *post2;
  Post *post3;
  int size;
} Desk;

Post *makePost (int data);
int isEmpty(Post *stack);
int push (Post **pStack, int data) ;
void pop (Post **pStack);
int top (Post *pStack);
int peekAndPop (Post **pStack);

//
Desk makeDesk (int size);
void displayDesk(Desk *desk);
void printPost (Post *post, int counter);

#endif /* functions_h */
