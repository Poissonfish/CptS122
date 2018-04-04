///////////////////////////////////////////////////////////////////////////////
/// \file         
/// \author       AO
/// \date         
/// \brief   You are to write a basic fitness application, in C++, 
///          that allows the user of the application to manually edit 
///          “diet” and “exercise” plans.For this application you will 
///          need to create three classes : DietPlan, ExercisePlan, and FitnessAppWrapper.     
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	// notice we are constructing an array of DietPlan objects, when
	// FitnessAppWrapper object is constructed because the list
	// is a member of the FitnessAppWrapper object! I placed a break point
	// in the DietPlan object's constructor. Debug and see what happens!
	cout << "Inside FitnessAppWrapper's constructor!" << endl;

}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "Inside FitnessAppWrapper's destructor!" << endl;
}

void FitnessAppWrapper::runApp() // will drive the application
{
	int option = 0;
	do
	{
		do // input validation loop
		{
			this->displayMenu();
			cin >> option;
		} while (option < 1 || option > 9); // validate the input; option must be [1 - 9]
		system("cls"); // not necessarily a portable/safe way to clear the screen
		// have obtained the option from the user; need to determine next operation
		this->performUserSelection(option);
	} while (option != 9); // 9 = exit the program
}

void FitnessAppWrapper::performUserSelection(const int &option)
{
	bool success = false;

	switch (option)
	{
	case 1: // load weekly DP
		this->loadWeeklyDietPlan();
		cout << "Diet plans loaded from dietPlans.txt!" << endl;
		break;
	case 2: // load weekly EP
		cout << "Not implemented!" << endl;
		break;
	case 3: // store weekly DP
		this->storeWeeklyDietPlan();
		cout << "Diet plans stored to dietPlans.txt!" << endl;
		break;
	case 4: // store weekly EP
		cout << "Not implemented!" << endl;
		break;
	case 5: // display weekly DP
		system("cls"); // not necessarily a portable/safe way to clear the screen
		this->displayWeeklyDietPlan();
		break;
	case 6: // display weekly EP
		cout << "Not implemented!" << endl;
		break;
	case 7: // edit daily DP
		success = this->editDietPlan();
		if (!success)
		{
			cout << "Could not find the diet plan specified!" << endl;
		}
		break;
	case 8: // edit daily EP
		cout << "Not implemented!" << endl;
		break;
	case 9: // exit
		this->storeWeeklyDietPlan();
		break;
	}
}

void FitnessAppWrapper::loadWeeklyDietPlan() // this will call the private loadWeeklyPlan() function
{
	// We want to start reading from the very beginning of the "dietPlan.txt" file.
	// We will close the stream associated with the "dietPlan.txt" file if it's open!
	if (this->mFstrDP.is_open()) // is_open () returns true if file open, false otherwise
	{
		this->mFstrDP.close(); // close it so we can start from the beginning of the file
	}
	else // file is not open - open it and read the week of plans from it
	{
		this->mFstrDP.open("dietPlans.txt"); // opens in input/output mode by default with fstream object
		this->loadWeeklyPlan(this->mFstrDP, this->mDPList);
		this->mFstrDP.close();
	}
}

void FitnessAppWrapper::displayWeeklyDietPlan() // this will call the private displayWeeklyPlan() function
{
	this->displayWeeklyPlan(this->mDPList); // display a weekly diet plan to the screen!
}

void FitnessAppWrapper::storeWeeklyDietPlan() // this will call the private storeWeeklyPlan() function
{
	// We want to start overwriting from the very beginning of the "dietPlan.txt" file.
	// We will close the stream associated with the "dietPlan.txt" file if it's open!
	if (this->mFstrDP.is_open()) // is_open () returns true if file open, false otherwise
	{
		// Note: since we are working with fstream objects, if the fstream is initially
		// asscoiated with extraction operations, then writing to it is a problem!
		// Close the stream and we'll not have issues!
		this->mFstrDP.close(); // close it so we can start from the beginning of the file
	}
	else // file is not open - open it and read the week of plans from it
	{
		this->mFstrDP.open("dietPlans.txt"); // opens in input/output mode by default with fstream object
		this->storeWeeklyPlan(this->mFstrDP, this->mDPList);
		this->mFstrDP.close();
	}
}

bool FitnessAppWrapper::editDietPlan() // will prompt the user for the name of the plan to edit
{
	system("cls");
	this->displayWeeklyDietPlan(); // provide the user with the plans
	cout << "Which diet plan would you like to edit (provide plan name)? ";
	// generally, it's more robust to use numerical values for comparisons
	// because it's very easy to mistype a string, but
	// will stick with std::string so we can practice std::string operations
	char planName[100] = "";
	cin.ignore(); // ignore next character in stream, which should be newline
	cin.getline(planName, 100);
	string stdPlanName = planName; // convert from char * to std::string, easier to perform comparisons

	bool success = false;
	// search for the plan name in the weekly plans;
	// if more than one plan has same name, just edit first one found
	for (int day = 0; day < 7; ++day)
	{
		// yes, we can compare std::string with == (I know it's amazing!)
		if (stdPlanName == this->mDPList[day].getPlanName())
		{
			success = true;
			this->mDPList[day].editGoal(); // call the DietPlan object's editGoal ()
		}
	}

	return success;
}

/////////////////// private member functions //////////////////////

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan; // extract 1 diet plan from the file through the fileStream -
						// uses overloaded file stream extraction operator -
						// (fstream, DietPlan)
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	// Note: in C++ we can declare a variable in the initialization expression.
	// However the variable can only be used inside of the for (). When the for ()
	// is done executing, the day variable is no longer available.
	for (int day = 0; day < 7; ++day) // 7 days in 1 week
	{
		this->loadDailyPlan(fileStream, weeklyPlan[day]); // read the plan for the current day
		char tempString[2];
		fileStream.getline(tempString, 2); // eat the blank line between each plan
	}
}

void FitnessAppWrapper::displayDailyPlan(const DietPlan &plan)
{
	cout << plan << endl; // write plan to standard display (screen) - 
				          // uses overloaded standard stream insertion operator -
				          // (ostream, DietPlan)
}

void FitnessAppWrapper::displayWeeklyPlan(const DietPlan weeklyPlan[])
{
	// Note: in C++ we can declare a variable in the initialization expression.
	// However the variable can only be used inside of the for (). When the for ()
	// is done executing, the day variable is no longer available.
	for (int day = 0; day < 7; ++day) // 7 days in 1 week
	{
		this->displayDailyPlan(weeklyPlan[day]); // write the plan for the current day to screen
		cout << endl; // write a blank line between each plan displayed!
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, const DietPlan &plan)
{
	fileStream << plan << endl; // write 1 diet plan to the file - 
	                            // uses overloaded file stream insertion operator -
	                            // (fstream, DietPlan)
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[])
{
	// Note: in C++ we can declare a variable in the initialization expression.
	// However the variable can only be used inside of the for (). When the for ()
	// is done executing, the day variable is no longer available.
	for (int day = 0; day < 7; ++day) // 7 days in 1 week
	{
		this->storeDailyPlan(fileStream, weeklyPlan[day]); // store the plan for the current day
		fileStream << endl; // write the blank line between each plan
	}
}

void FitnessAppWrapper::displayMenu()
{
	cout << "1.\tLoad weekly diet plans from file." << endl;
	cout << "2.\tLoad weekly exercise plans from file." << endl;
	cout << "3.\tStore weekly diet plans to file." << endl;
	cout << "4.\tStore weekly exercise plans to file." << endl;
	cout << "5.\tDisplay weekly diet plans to screen." << endl;
	cout << "6.\tDisplay weekly exercise plans to screen." << endl;
	cout << "7.\tEdit daily diet plan." << endl;
	cout << "8.\tEdit daily exercise plan." << endl;
	cout << "9.\tExit." << endl;
}