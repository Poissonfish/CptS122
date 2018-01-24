/*
Programming Assignment 1
Date : Jan 24, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program read a csv file and compute the descriptive statistics,
then export the results to another csv file.
*/

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
	infile = openFile("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA1/FitbitData.csv", "r");
	outfile = openFile("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA1/result.csv", "w");
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
