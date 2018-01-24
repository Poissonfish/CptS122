# include "functions.h"
# include "functions.c"

int main(void) {
	printf("Program stars\n");
	// Variables for files access
	FILE *infile = NULL,
		 *outfile = NULL;
	// Variable for fitbitdata
	FitbitData *data;
	// Read the file
	infile = openFile("FitbitData.csv", "r");
	outfile = openFile("result.csv", "w");
	// Import data
	printf("Importing\n");
	data = importData(infile, 100, ",");
	// Export result
	printf("Exporting\n");
	exportResult(outfile, data);
	// Close files
	closeFile(infile);
	closeFile(outfile);
	printf("Program ends\n");
}
