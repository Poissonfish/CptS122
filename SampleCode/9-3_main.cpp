#include "Node.h"
#include "BST.h"

int main(void)
{
	BST tree;
	Data d1, d2, d3, d4;
	Rational r1(5, 1);
	d1.setRational(r1);//(*(new Rational(5, 1)));//(r1);
	tree.insert(d1); // insert 5/1

	r1.setNumerator(3);
	d2.setRational(r1);
	tree.insert(d2); // insert 3/1

	r1.setNumerator(10);
	d3.setRational(r1);
	tree.insert(d3); // insert 10/1

	r1.setNumerator(4);
	d4.setRational(r1);
	tree.insert(d4); // insert 4/1

	tree.inorderTraversal();
	tree.postorderTraversal();

	return 0;
}