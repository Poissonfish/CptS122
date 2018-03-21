# pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

class Menu {
public:
  // Display the menu
  void displayMenu();
  // Display the submenu;
  void displaySubMenu();
  // Get option from user and implement the feature
  int getMenuOption() const;
};

