#include "Menu.hpp"

void Menu::displayMenu() {
  cout << "Hi, welcome to use my Attendance Tracker!" << endl;
  cout << "1. Import course lise." << endl;
  cout << "2. Load master list." << endl;
  cout << "3. Store master list." << endl;
  cout << "4. Mark absences." << endl;
  cout << "5. Edit absences" << endl;
  cout << "6. Generate report." << endl;
  cout << "7. Exit." << endl;
  cout << "Please enter an option (1 ~ 7) : ";
}

void Menu::displaySubMenu() {
  cout << "Which report you'd like to generate?" << endl;
  cout << "1. Generate report for all students, showing only the most recent absence for each student." << endl;
  cout << "2. Generate report for students with absences that match or exceed the input number" << endl;
  cout << "Please enter an option (1 or 2) : ";
}

int Menu::getMenuOption() const {
  int option = 0;
  cin >> option;
  return option;
}
