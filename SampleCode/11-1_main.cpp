// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

// History: 4/6 - Introducted virtual Employee destructor and
//                a pure virtual function for calculatePay ()
//                that makes Employee an abstract class now.
//                We can no longer instantiate an Employee class,
//                but we can still use pointers or references
//                to Employee types.
//          4/4 - Further explored polymorphism. Check out the loops
//                in main ()!
//          4/2 - Discussed keyword virtual and polymorphism. Added
//                virtual to Employee::calculatePay () and
//                created non member printPay (), which
//                is a single function that is capable
//                of printing a the pay for an Employee or a Manager.
//          3/30 - Discussed different forms of inheritance,
//                 looked at different inheritance specifiers,
//                 declared the Officer class.
//          3/28 - Completed the Manager::calculatePay ();
//                 worked with underdstanding the order of operations
//                 with the Employee and Manager constructors/destructors

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.h"
#include "Manager.h"
#include "Officer.h"

// added printPay ()
void printPay(Employee &e); // must be using * or & to base class

int main(void)
{
//	Employee *pE = nullptr, *pM = nullptr;
	//int count = 0;

	int numEmployees = 0;
	Employee *empl[100];
	cout << "Enter num of Employes to hire: ";
	cin >> numEmployees;

	// we don't know how many total times upfront that
	// this loop will iterate; this is an important observation!
	for (int i = 0; i < numEmployees; ++i)
	{
		int employeeType = 0; // 1 - basic employee, 2 - means manager
		cout << "Enter employee type (1) basic (2) manager: ";
		cin >> employeeType; // we don't know upfront what types of 
		                     // employees will be hired! This is an
		                     // important observation.

		//if (employeeType == 1)
		//{
		//	empl[i] = new Employee("Shelly", 25.00, 80);
		//	//printPay(*empl[i]);
		//}
		if (employeeType == 2)
		{
			empl[i] = new Manager("Joey", 3000, 80, true);
			//printPay(*empl[i]);
		}
		printPay(*empl[i]);

	}	
	delete empl[0];

	//Employee e1("Andy");
	//e1.setHours(100);

	//cout << e1.getName() << " : " << 
	//	e1.getPayRate() << " : " << e1.calculatePay() << endl;

	//Manager m1("Anthony");
	////m1.
	//m1.setIsSalaried(true);
	//m1.setPayRate(1200);
	//cout << m1.getName() << " : " << 
	//	m1.getPayRate() << " : " << m1.calculatePay() << endl;

	//Officer o1;

	return 0;
}

// This kind of function needs to accept either a pointer
// to a base class type or a reference to one.
void printPay(Employee &e)
{
	// Since calculatePay () is virtual, the
	// calculatePay () belonging to a Manager could 
	// be dynamically bound to the object even
	// though we have an Employee handle. This is
	// polymorphism!
	cout << e.calculatePay() << endl;
}