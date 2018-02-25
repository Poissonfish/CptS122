#include "TestApp.h"

// this is a non-member function - can use to wrap all of the tests; of course, could also have a member function, which does this. Consider the differences!
void runTestSuite(void)
{
	TestApp t;
	t.testDebitAccount();
	t.testCreditAccount();
}

void TestApp::testCreditAccount(void)
{
	Account testAccount(100.00, 1, "test name", "February 26, 2016"); // $100.00 is the initial balance

	if (testAccount.credit(10.00) == 110.00) // try to credit $10.00 from the account, i.e. new balance = $100.00 + $10.00 = $110.00
	{
		cout << "test 1 credit () Account passed" << endl;
	}
	else
	{
		cout << "test 1 credit () Account failed" << endl;
	}
}