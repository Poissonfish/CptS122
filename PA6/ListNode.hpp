#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include "Stack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::strcmp;
using std::string;
using std::fstream;

enum Level {Freshman, Sophomore, Junior, Senior, Graduate, Unknown};

class ListNode {
public:
    ListNode();
    ListNode(int record, int id, string name, string email, string units, string program, Level level);
    ListNode(const ListNode &copy);
    ~ListNode();

    // Getters
    int getRecord() const;
    int getID() const;
    string getName() const;
    string getEmail() const;
    string getUnits() const;
    string getProgram() const;
    Level getLevel() const;
    int getAbsence() const;
    Stack *getStack() const;
    string getDate() const;
    ListNode *getNext() const;

    // Setters
    void setData(int record, int id, string name, string email, int units, string program, Level level);
    void setRecord(const int record);
    void setID(const int id);
    void setName(const string name);
    void setEmail(const string email);
    void setUnits(const string units);
    void setProgram(const string program);
    void setLevel(const string input);
    void setDate(Stack *stack);
    void setAbsence(const int n);
    // increase absence by 1
    void addAbsence();
    // push date into the stack
    void pushDate(Date *newDate);
    // set the next node
    void setNext(ListNode *const newNext);

private:
    int record;
    int id;
    string name;
    string email;
    string units;
    string program;
    Level level;
    int nAbsence;
    Stack *dateAbsence;
    ListNode *pNext;
};

fstream & operator>> (fstream &lhs, ListNode &rhs);
ostream & operator<< (ostream &lhs, const ListNode &rhs);
fstream & operator<< (fstream &lhs, const ListNode &rhs);
