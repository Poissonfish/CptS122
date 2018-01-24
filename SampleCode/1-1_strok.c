// This example is for review purposes. 

// History: 1/12/18 - Redesigned our algorithm for separating a string
//                    into tokens (substrings). Introduced a struct student
//                    to store three strings (i.e. last name, first name,
//                    major). Currently, the last name field (pLast)
//                    is declared as a char *. This may cause issues. Why?
//                    Refer to the comments towards the end of main () and
//                    try out the exercise!

//          1/10/18 - Opened a .csv file, read one line from it,
//                    separated the line into tokens/values using
//                    strtok ()

#include <stdio.h> // printf (), scanf ()
#include <string.h> // strcpy (), strncpy (), strcat (),
                    // strncat (), strcmp (), strlen (),
                    // strtok ()

typedef struct student
{
	char *pLast; // If we declare this field as a pointer, then
	             // there is no memory allocated for storing
                 // an actual string yet. We'd consider
	             // using malloc () for the string.
	char first[100];
	char major[100];
}Student;

int main(int argc, char *argv[])
{
	FILE *infile = NULL;
	char line[100] = "", copyLine[100] = "";
	char *pTokens[10] = { NULL };
	int index = 0;
	Student s1 = {NULL, "", ""};

	// we are working with a comma-separated values file (.csv)
	infile = fopen("data.csv", "r");

	if (infile != NULL)
	{
		// success
		//fscanf();
		printf("line: %d\n", line);
		fgets(line, 100, infile); // read one line from the file,
                                  // including whitespace
		puts(line); // echo the line read from the file
		strcpy(copyLine, line); // we'll copy the original line,
		                        // since strtok () modifies
		                        // the string every time it
		                        // detects a delimiter
		// lets separate the line into each
		// value or cell
		pTokens[index] = strtok(copyLine, ","); // first token
		//++index;

		while (pTokens[index] != NULL)
		{
			++index;
			pTokens[index] = strtok(NULL, ","); // token
			
		}
		//pTokens[2] = strtok(NULL, ","); // third token
		//puts(pTokens[2]); // echo the third token to the screen

		strcpy(s1.major, pTokens[2]);
		puts(s1.major);
		strcpy(s1.first, pTokens[1]);
		puts(s1.first);
		strcpy(s1.pLast, pTokens[0]); // will this work? No! 
		                              // there's currently no
		                              // memory for the actual 
		                              // string; it will crash here!
		                              // change the pLast to an array
		                              // i.e. char pLast[100]. Does it work
		                              // now? Yes!
		puts(s1.pLast);
	}

	return 0;
}