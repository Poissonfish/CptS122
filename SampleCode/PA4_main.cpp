///////////////////////////////////////////////////////////////////////////////
/// \file         Main Program App (main.cpp)
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///               Limited error checking is provided.
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

//Problem Statement:
//Note: This project is similar to the Account Class
//problem provided in your Deitel and Deitel C How To
//Program book. You are to write a
//basic bank application, in C++, that allows the user
//of the application to manually create,
//modify, and delete bank accounts. Before you write the
//application you will need to create a class called Account.
//The class Account is used to represent customers' bank
//accounts. Your class should include four data members to
//represent the account balance (a double), account number
//(an integer), customer name (a string), and date the
//account was opened (a string).
//Your class should provide two constructors: one default
//constructor with no parameters and one constructor with
//the initial balance, account
//number, customer name, and date created as parameters.
//The second constructor should check the initial balance.
//If the balance is not >= 0, the balance should be set to 0
//and an error message should be displayed.
//
//The class should provide several member functions. Some
//of which are described below. Remember that you will have
//to think about other appropriate member functions (think
//about setter and getter functions!). Member function credit
//should
//add an amount to the current balance and store it back into
//the balance. Member function debit should withdraw money
//from the Account, modify
//the balance, and ensure the debit amount does not exceed
//the Account's balance. If it does, the balance should be
//left unmodified and the function
//should print an appropriate message. Member function
//printAccountInfo should print the current balance, account
//number, customer name, and date of the account.
//
//Once you have designed your Account class. You will need to
//create the main bank program. Note that you can create the
//main bank program
//in the main function or you can try to create another class
//for the main bank program. The main program needs to display
//a menu for adding,
//deleting, modifying, and displaying accounts. You decide
//appropriate menu features! Have fun with this assignment! 

#include "BankManager.h"
#include "TestApp.h"

int main(void)
{

	runTestSuite(); // run the series of tests available


	BankManager bankApp;

	bankApp.runBankApplication(); // run the actual application for the bank system

	return 0;
}