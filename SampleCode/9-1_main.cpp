#include "ListApp.h"

void testInsertInOrder();
void testInsertAtEnd();
void testDeleteAtFront(List &builtList);
void testDeleteNode(List &builtList);
void testDeleteAtEnd();

int main(void)
{
	// Start with debugging this project! "Step Into" each statement to answer the questions!
	// Question 1: what function is called in the statement below?
	//ListNode n1;
	//// Question 2: what function is called in the statement below?
	//ListNode n2(42); // shallow or deep copy?
	//// Question 3: what function is called in the statement below?
	//ListNode n3(n2); // shallow or deep copy?
	//// Question 4: what function is called in the statement below?
 //	ListNode n4 = n3; // shallow or deep copy?
	//
	//ListNode n5;
	//// Question 5: what function/operator is called in the statement below?
	//n5 = n4; // did we explicitly implement this function/operator? 

	//// Question 6: what function is called in the statement below?
	//List l1;
	//// make sure that you finish implementing the copy constructor for the List object before you try to 
	//// execute the next statement!
	//// Question 7: what function is called in the statement below? What would happen if we did not 
	////             explicitly implement the function? Would the compiler generated one be good enough?
	// List l2 = l1; // shallow or deep copy?
	//// Question 8: what would happen if a shallow copy constructor is used, instead of a deep copy constructor, 
	////             when the destructor for each list object is implicily invoked? l2 and l1 would have the same
	////             address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	////             out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!


	//List l3;
	//// make sure that you finish implementing the overloaded assignment for the List object before you try to 
	//// execute the next statement!
	//// Question 9: what function is called in the statement below? What would happen if we did not 
	////             explicitly implement the function? Would the compiler generated one be good enough?
	// l3 = l2; // shallow or deep copy? 
	//// Question 10: what would happen if a shallow copy assignment is used, instead of a deep copy assignment, 
	////              when the destructor for each list object is implicily invoked? l3 and l2 would have the same
	////              address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	////              out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!

	//// Question 11: how does the List destructor free up the nodes? You will need to visit "List.cpp" to answer this question!

	//Test functions
	testInsertInOrder();
	testInsertAtEnd();
	testDeleteAtEnd();

	ListApp app;
	cout << "Running app..." << endl;
	app.runApp();
	cout << "Check ExamStats.txt for output" << endl;
	system("pause");

	return 0;
}

void testInsertInOrder()
{
	List testList;
	
	cout <<"Testing insert in order:" << endl;
	cout << "Inserting 5" << endl;
	testList.insertInOrder(5);
	cout << "Inserting 10" << endl;
	testList.insertInOrder(10);
	cout << "Inserting -5" << endl;
	testList.insertInOrder(-5);
	cout << "Inserting 3" << endl;
	testList.insertInOrder(3);
	cout << "Inserting 20" << endl;
	testList.insertInOrder(20);
	cout << "Inserting 100" << endl;
	testList.insertInOrder(100);
	cout << "Inserting 75" << endl << endl;
	testList.insertInOrder(75);

	cout << "Final list: " << endl << testList;
	system("pause");
	testDeleteAtFront(testList);
	system("pause");
}

void testDeleteNode(List &builtList)
{
	int value = 0;
	cout << "Enter a value to delete: ";
	cin >> value;

	builtList.deleteNode(value);

	cout << "Entire List: " << endl << builtList << endl;
}

void testDeleteAtFront(List &builtList)
{
	cout << "Testing deleteAtFront(): " << endl << endl;
	while (!builtList.isEmpty())
	{
		cout << "Entire list: " << endl << builtList << endl;
		cout << "Deleting at front..." << endl;
		builtList.deleteAtFront();
	}
}

void testInsertAtEnd()
{
	List testList;

	cout << endl << "Testing insert at end" << endl;
	cout << "Inserting 5" << endl;
	testList.insertAtEnd(5);
	cout << "Inserting 10" << endl;
	testList.insertAtEnd(10);
	cout << "Inserting -5" << endl;
	testList.insertAtEnd(-5);
	cout << "Inserting 3" << endl;
	testList.insertAtEnd(3);
	cout << "Inserting 20" << endl;
	testList.insertAtEnd(20);
	cout << "Inserting 100" << endl;
	testList.insertAtEnd(100);
	cout << "Inserting 75" << endl << endl;
	testList.insertAtEnd(75);

	cout << "Final list: " << endl << testList;
	system("pause");

	testDeleteNode(testList);
	system("pause");
}

void testDeleteAtEnd()
{
	List builtList;
	builtList.insertAtEnd(12);
	builtList.insertAtEnd(33);
	builtList.insertAtEnd(55);
	cout << "Testing deleteAtEnd(): " << endl;
	cout << "New List: " << endl << builtList << endl;
	cout << "Deleting last node..." << endl;
	builtList.deleteAtEnd();
	cout << "Entire List: " << endl << builtList << endl;
	system("pause");
}