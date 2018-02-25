///////////////////////////////////////////////////////////////////////////////
/// \file         BankManager.h
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This is where we build our tests for the bank application.
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include "BankManager.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void runTestSuite(void); // non-member function

						 // These are not exhaustive tests! Many more could be implemented!
class TestApp
{
public:
	// Generally, we should only define the function in the class definition if it's simple. For this example I'll show both ways!
	void testDebitAccount(void)
	{
		Account testAccount(100.00, 1, "test name", "October 1, 2015"); // $100.00 is the initial balance

		if (testAccount.debit(10.00) == 90.00) // try to debit $10.00 from the account, i.e. new balance = $100.00 - $10.00 = $90.00
		{
			cout << "test 1 debit () Account passed" << endl;
		}
		else
		{
			cout << "test 1 debit () Account failed" << endl;
		}
	}

	void testCreditAccount(void); // Defining in TestApp.cpp - note the difference

private:
	// No need to have a private data member - will declare all account objects locally in the test drivers
};