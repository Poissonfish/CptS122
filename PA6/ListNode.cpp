#include "ListNode.hpp"

ListNode::ListNode() {
  this->record = -1;
  this->id = -1;
  this->name = "";
  this->email = "";
  this->units = "";
  this->program = "";
  this->level = Unknown;
  this->nAbsence = 0;
  this->dateAbsence = new Stack();
  this->pNext = nullptr;
}

ListNode::ListNode(int record, int id, string name, string email, string units, string program, Level level) {
  this->record = record;
  this->id = id;
  this->name = name;
  this->email = email;
  this->units = units;
  this->program = program;
  this->level = level;
  this->nAbsence = 0;
  this->dateAbsence = new Stack();
  this->pNext = nullptr;
}

ListNode::ListNode(const ListNode &copy) {
  this->record = copy.getRecord();
  this->id = copy.getID();
  this->name = copy.getName();
  this->email = copy.getEmail();
  this->units = copy.getUnits();
  this->program = copy.getProgram();
  this->level = copy.getLevel();
  this->nAbsence = copy.getAbsence();
  this->dateAbsence = copy.getStack();
  this->pNext = copy.getNext();
}

ListNode::~ListNode() {
  // delete &(this->record);
  // delete &(this->id);
  // delete &(this->name);
  // delete &(this->email);
  // delete &(this->units);
  // delete &(this->program);
  // delete &(this->level);
}

int ListNode::getRecord() const {
  return this->record;
}

int ListNode::getID() const {
  return this->id;
}

string ListNode::getName() const {
  return this->name;
}

string ListNode::getEmail() const {
  return this->email;
}

string ListNode::getUnits() const {
  return this->units;
}

string ListNode::getProgram() const {
  return this->program;
}

Level ListNode::getLevel() const {
  return this->level;
}

int ListNode::getAbsence() const {
  return this->nAbsence;
}

Stack *ListNode::getStack() const {
  return this->dateAbsence;
}

string ListNode::getDate() const {
  if (this->dateAbsence->isEmpty())
    return "NA";
  else
    return this->dateAbsence->peek()->getDate();
}

ListNode *ListNode::getNext() const {
  return this->pNext;
}

void ListNode::setData(int record, int id, string name, string email, int units, string program, Level level) {
  this->record = record;
  this->id = id;
  this->name = name;
  this->email = email;
  this->units = units;
  this->program = program;
  this->level = level;
  this->pNext = nullptr;
}

void ListNode::setRecord(const int record) {
  if (record > 0 && record < 1000)
    this->record = record;
  else
    this->record = -1;
}

void ListNode:: setID(const int id) {
  if (id > 0 && id < 1000000000)
    this->id = id;
  else
    this->id = -1;
}

void ListNode::setName(const string name) {
  this->name = name;
}

void ListNode::setEmail(const string email) {
  this->email = email;
}

void ListNode::setUnits(const string units) {
  if (units.compare("1") == 0)
    this->units = "1";
  else if (units.compare("2") == 0)
    this->units = "2";
  else if (units.compare("3") == 0)
    this->units = "3";
  else if (units.compare("4") == 0)
    this->units = "4";
  else if (units.compare("AU") == 0)
    this->units = "AU";
  else
    this->units = "Unknown";
}

void ListNode::setProgram(const string program) {
  this->program = program;
}

void ListNode::setLevel(const string input) {
  if (!input.compare("Freshman"))
    this->level = Freshman;
  else if (!input.compare("Sophomore"))
    this->level = Sophomore;
  else if (!input.compare("Junior"))
    this->level = Junior;
  else if (!input.compare("Senior"))
    this->level = Senior;
  else if (!input.compare("Graduate"))
    this->level = Graduate;
  else
    this->level = Unknown;
}

void ListNode::setDate(Stack *stack) {
    this->dateAbsence = stack;
}

void ListNode::setAbsence(const int n) {
  this->nAbsence = n;
}

void ListNode::addAbsence() {
  this->nAbsence++;
}

void ListNode::pushDate(Date *newDate) {
  cout << "Date: " << newDate->getDate() << endl;
  this->dateAbsence->push(newDate);
}


void ListNode::setNext(ListNode *const newNext) {
  this->pNext = newNext;
}

fstream & operator>> (fstream &lhs, ListNode &rhs) { // Why sometimes we need const before rhs object?
    string strTemp;
    int intTemp;
    // Load record
    getline(lhs, strTemp, ',');
    std::stringstream streamRec(strTemp);
    streamRec >> intTemp;
    rhs.setRecord(intTemp);
    // Load id
    getline(lhs, strTemp, ',');
    std::stringstream streamID(strTemp);
    streamID >> intTemp;
    rhs.setID(intTemp);
    // Load name
    getline(lhs, strTemp, '"');
    getline(lhs, strTemp, '"');
    rhs.setName(strTemp);
    // Load email
    getline(lhs, strTemp, ',');
    getline(lhs, strTemp, ',');
    rhs.setEmail(strTemp);
    // Load units
    getline(lhs, strTemp, ',');
    rhs.setUnits(strTemp);
    // Load program
    getline(lhs, strTemp, ',');
    rhs.setProgram(strTemp);
    // Load level (and absence in other case)
    getline(lhs, strTemp);
    // see if contain absence information
    int found = strTemp.find(",");
    bool isMasterList = found != std::string::npos;
   // set level
    int i = 0;
    while (i < strTemp.length()) {
        if (isalpha(strTemp.at(i)))
            i ++;
        else
            break;
    }
    rhs.setLevel(strTemp.substr(0, i));
    // if is a master list
    if (isMasterList) {
        strTemp.erase(0, i + 1);
        Stack *stackTemp = new Stack();
        Stack *stackDate = new Stack();
        Date *newDate = new Date();
        string token = "";
        for (int i = 0; i < 8; i ++) {
            found = strTemp.find(",");
            if (found != std::string::npos) {
                token = strTemp.substr(0, found);
                strTemp.erase(0, found + 1);
            }
            newDate->setDate(token);
            stackTemp->push(newDate);
        }
        // push back to ensure the order is right
        while (!stackTemp->isEmpty()) {
            newDate = stackTemp->pop();
            stackDate->push(newDate);
        }
        rhs.setAbsence(stackDate->getSize());
        rhs.setDate(stackDate);
    }
    // Return
    return lhs;
}

ostream & operator<< (ostream &lhs, const ListNode &rhs) {
    lhs << rhs.getRecord() << ",";
    lhs << rhs.getID() << ",";
    lhs << '"' << rhs.getName() << '"' << ",";
    lhs << rhs.getEmail() << ",";
    lhs << rhs.getUnits() << ",";
    lhs << rhs.getProgram() << ",";
    switch(rhs.getLevel()) {
        case Freshman: lhs << "Freshman";
        break;
        case Sophomore: lhs << "Sophomore";
        break;
        case Junior: lhs << "Junior";
        break;
        case Senior: lhs << "Senior";
        break;
        case Graduate: lhs << "Graduate";
        break;
        case Unknown: lhs << "Unknown";
        break;
    }
//    Stack *stackTemp = new Stack();
//    // deep copy
//    *(stackTemp) = *(rhs.getStack());
//    for (int i = 0; i < stackTemp->getSize(); i ++)
//        lhs << "," << *(stackTemp->pop());
//    int diff = 8 - stackTemp->getSize();
//    for (int i = 0; i < diff; i ++)
//        lhs << ",0000/00/00";
    return lhs;
}

fstream &operator<< (fstream &lhs, const ListNode &rhs) {
    lhs << rhs.getRecord() << ",";
    lhs << rhs.getID() << ",";
    lhs << '"' << rhs.getName() << '"' << ",";
    lhs << rhs.getEmail() << ",";
    lhs << rhs.getUnits() << ",";
    lhs << rhs.getProgram() << ",";
    switch(rhs.getLevel()) {
        case Freshman: lhs << "Freshman";
        break;
        case Sophomore: lhs << "Sophomore";
        break;
        case Junior: lhs << "Junior";
        break;
        case Senior: lhs << "Senior";
        break;
        case Graduate: lhs << "Graduate";
        break;
        case Unknown: lhs << "Unknown";
        break;
    }
    return lhs;
}
