#include <iostream> // <stdio.h>

// same name for function - ok, in C++, called function overloading
// overloaded functions have to be different by number of parameters,
// or order of parameter types, or just different parameter types
void divide(int n1, int n2, int *pResult, int *pRem);
void divide(int n1, int n2, int &result, int &rem);

int main(void)
{
	// cout is an output stream object, i.e. ostream type
	std::cout << "Hello CptS 122!" << std::endl;

	std::cout << "Enter a number: ";

	int n1 = 0;

	// cin is an input stream object, i.e. istream type
	std::cin >> n1;
	std::cout << "Number: " << n1 << std::endl;

	int result = 0, rem = 0;

	divide(7, 3, &result, &rem); // passing-by-pointer
	std::cout << "Result: " << result << " Rem: " << rem << std::endl;

	divide(11, 4, result, rem); // passing-by-reference
	std::cout << "Result: " << result << " Rem: " << rem << std::endl;


	return 0;
}

// we are passing-by-pointer
void divide(int n1, int n2, int *pResult, int *pRem)
{
	*pResult = n1 / n2;
	*pRem = n1 % n2;
}

// we are passing-by-reference -- that's the & next to the parameter
void divide(int n1, int n2, int &result, int &rem)
{
	result = n1 / n2;
	rem = n1 % n2;
}
