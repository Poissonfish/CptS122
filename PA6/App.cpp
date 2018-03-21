#include "App.hpp"

App::App() {
  list = new List();
  menu = new Menu();
  // fileMasterList.open("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA6/masterList.txt", std::ios::out);
}

App::~App() {
  fileClassList.close();
  fileMasterList.close();
  fileReportOne.close();
  fileReportTwo.close();
}

void App::run() {
    int option = 0;
    while (option != 7) {
        option = 0;
        menu->displayMenu();
        while (option > 7 || option < 1)
            option = menu->getMenuOption();
        switch(option) {
            case 1: importCourse();
            break;
            case 2: loadMasterList();
            break;
            case 3: storeMasterList();
            break;
            case 4: markAbsence();
            break;
            case 5: editAbsence();
            break;
            case 6: makeReport();
            break;
        }
        if (option < 7 && option > 0) {
            cout << "Done" << endl;
            stop();
            clean();
        }
    }
    storeMasterList();
}

void App::importCourse() {
  fileClassList.open("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA6/classList.csv", std::ios::in);
  fileClassList >> *(this->list);
  fileClassList.close();
}

void App::loadMasterList() {
    fileMasterList.open("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA6/masterList.txt", std::ios::in);
    fileMasterList >> *(this->list);
    fileMasterList.close();
}

void App::storeMasterList() {
    fileMasterList.open("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA6/masterList.txt", std::ios::out);
    ListNode *pCur = list->getHead();
    fileMasterList << ",ID,Name,Email,Units,Program,Level,Absence 1,Absence 2,Absence 3,Absence 4,Absence 5,Absence 6,Absence 7,Absence 8" << endl;
    while (pCur != nullptr) {
        fileMasterList << *pCur;
        // WHY there is a memory issue when I declare as an object instead of a pointer
        Stack *stackTemp = new Stack();
        // deep copy
        *(stackTemp) = *(pCur->getStack());
        int size = stackTemp->getSize();
        for (int i = 0; i < size; i ++)
            fileMasterList << "," << *(stackTemp->pop());
        int diff = 8 - stackTemp->getSize();
        for (int i = 0; i < diff; i ++)
            fileMasterList << ",0000/00/00";
        fileMasterList << endl;
        pCur = pCur->getNext();
    }
    fileMasterList.close();
}

void App::markAbsence() {
  ListNode *pCur = this->list->getHead();
  while (pCur != nullptr) {
    string strTemp = "";
    cout << "Was " << pCur->getName() << " absence today? (Y/N) : ";
    while (!isYes(strTemp) && !isNo(strTemp))
      cin >> strTemp;
    if (isYes(strTemp)) {
      pCur->addAbsence();
      Date *date = new Date();
      pCur->pushDate(date);
    }
    pCur = pCur->getNext();
  }
}

void App::editAbsence() {
    cout << *(this->list) << endl;
    int inputID;
    int inputDate;
    cout << "Which student you'd like to edit?" << endl;
    cout << "Please input his/her ID : ";
    cin >> inputID;
    ListNode *pCur = this->list->getHead();
    bool isFound = false;
    while (pCur != nullptr) {
        if (pCur->getID() == inputID && !pCur->getStack()->isEmpty()) {
            isFound = true;
            pCur->getStack()->printStack();
            cout << "Which date you'd like to change?" << endl;
            cout << "Please input the index for that date(integer) : ";
            cin >> inputDate;
            pCur->getStack()->removeAtN(inputDate - 1);
            break;
        }
        pCur = pCur->getNext();
    }
    if (!isFound)
        cout << "Can't find this student or absence record!" << endl;
}

void App::makeReport() {
  int option = 0;
  menu->displaySubMenu();
  option = menu->getMenuOption();
  switch(option) {
    case 1: makeReportOne();
    break;
    case 2: makeReportTwo();
    break;
  }
}

void App::makeReportOne() {
    fileReportOne.open("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA6/report1.txt", std::ios::out);
    ListNode *pCur = list->getHead();
    fileReportOne << ",ID,Name,Email,Units,Program,Level,TimeOfAbsence,LastAbsence" << endl;
    while (pCur != nullptr) {
        fileReportOne << *pCur;
        fileReportOne << "," << to_string(pCur->getAbsence()) << "," << *(pCur->getStack()->peek()) << endl;
        pCur = pCur->getNext();
    }
    fileReportOne.close();
}

void App::makeReportTwo() {
    int value = 0;
    cout << "What's the threshold for filtering by number of absence? Input a number : ";
    cin >> value;
    cout << endl;
    fileReportTwo.open("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA6/report2.txt", std::ios::out);
    ListNode *pCur = list->getHead();
    fileReportTwo << ",ID,Name,Email,Units,Program,Level,TimesOfAbsence,LastAbsence" << endl;
    while (pCur != nullptr) {
        if (pCur->getAbsence() >= value) {
            fileReportTwo << *pCur;
            fileReportTwo << "," << to_string(pCur->getAbsence()) << "," << *(pCur->getStack()->peek()) << endl;
        }
        pCur = pCur->getNext();
    }
    fileReportTwo.close();
}

bool isYes(string input) {
  if (!input.compare("Y") || !input.compare("Yes") || !input.compare("y") || !input.compare("yes"))
    return true;
  else
    return false;
}

bool isNo(string input) {
  if (!input.compare("N") || !input.compare("No") || !input.compare("n") || !input.compare("no"))
    return true;
  else
    return false;
}

void clean() {
    system("cls"); // Windows
//  system("clear"); // Mac
}

void stop() {
    printf("\n<Press Enter to Continue>\n");
    getchar();
    getchar();
}
