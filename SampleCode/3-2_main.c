#include "Stack.h"
#include "TestStack.h"

int main(void)
{
	//char *str = "this is a string";
	char str[100] = "this is a string", *pStr = NULL;

	pStr = reverseString(str);

	printf("%s\n", str);

	return 0;
}