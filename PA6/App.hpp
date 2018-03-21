#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>

#include "Menu.hpp"
#include "List.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::string;
using std::fstream;

class App {
public:
    App();
    ~App();

    // import course list and overwrite the master list in the program
    void importCourse();
    // import information from file masterlist.txt and overwrite the master list in the program
    void loadMasterList();
    // export information from the master list in the program to file masterlist.txt
    void storeMasterList();
    // mark absence for students today
    void markAbsence();
    // edit record for specific student for specific date
    void editAbsence();
    // generate report
    void makeReport();
    // generate report with number of time being absence and last absence date
    void makeReportOne();
    // generate report that meet the threshold
    void makeReportTwo();
    // run the program
    void run();

private:
  List *list;
  Menu *menu;
  fstream fileClassList;
  fstream fileMasterList;
  fstream fileReportOne;
  fstream fileReportTwo;
};

// determine if user input is yes or not
bool isYes(string input);
// determine if user input is no or not
bool isNo(string input);
// Clean the screen
void clean();
// Pause the program until <enter> input
void stop();

