#include "LinkedList.h"

// History: 1/24/18 - Implemented InsertInOrder (), started
//                    deleteStudent ()
//          1/22/18 - Implemented deleteAtFront (), 
//                    which we'll use as a function to learn
//                    how to test. Also, implemented printListRec ()
//          1/19/18 - Defined struct node, implemented
//                    makeNode (), insertAtFront (),
//                    and executed 1 case for insertAtFront ()
//
//          1/17/18 - Defined struct student, discussed
//                    operations and behavior of lists

int main(int argc, char *argv[])
{
	Student list[200]; // We could implement a list data structure
	                   // with an array. However, we're going to use
                       // links/pointers.

	Node *pList = NULL; // this is a pointer to the first
	                    // node in our singly linked list
	Student s1 = {111111, "last, first"},
		*pStudent = NULL;
	int success = 0;

	success = insertAtFront(&pList, s1);
	success = insertAtFront(&pList, s1);
	success = insertAtFront(&pList, s1);
	success = insertAtFront(&pList, s1);

	printf("%d %s\n", pList->s.id, pList->s.name);

	pStudent = deleteAtFront(&pList);

	printf("%d %s\n", pStudent->id, pStudent->name);
	printf("%d\n", pList);

	printListRec(pList);

	return 0;
}