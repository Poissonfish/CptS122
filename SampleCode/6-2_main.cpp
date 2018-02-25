// History: 2/16 - Implemented an enqueue ()/insert function for
//                 a queue. Introduced some basic file processing
//                 with std::fstream objects.

#include "Queue.h"
#include <fstream>

using std::fstream;

int main(void)
{
	Node n1, n2("printjob1");

	fstream input("printjobs.txt");

	//input.open()

	string s1 = "";
	input >> s1;
	cout << s1 << endl;
	input >> s1;
	cout << s1 << endl;
	char s2[100] = "";
	input.getline(s2, 100);
	cout << s2 << endl;

	// nonmember - getline()

	input.close();

	return 0;
}