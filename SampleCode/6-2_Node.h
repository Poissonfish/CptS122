#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Node
{
public:
	Node(const string &newPrintJob = "");
	Node(const Node &newNode);
	~Node();

	string getPrintJob() const;
	Node * getNextPtr() const;

	void setPrintJob(const string &newPrintJob);
	void setNextPtr(Node * const newNextPtr);

private:
	string mPrintJob;
	Node *mpNext;
};