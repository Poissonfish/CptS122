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

FILE * openFile(char* name, char* mode) {
	FILE *infile = NULL;
	infile = fopen(name, mode);
	// Check if file read successfully
	if (infile == NULL) {
		printf("Could not open file %s!\n", name);
		printf("Exiting!\n");
		exit(1);
	}
	else
		printf("Successfully read file %s!\n", name);
	return infile;
}


void closeFile(FILE *file) {
	printf("Closing file!\n");
	fclose(file);
}


char ** strsplit(char *input, const char *delim) {
	// Allocate memory in heap(permanent) instad of stack(temporary)
	char **strings = malloc(sizeof(char*) * 7);
	// Get pointer from input string
	strings[0] = input;
	for (int i = 1; i < 7; i++) {
		// Get position of delim from last start point (i - 1)
		strings[i] = strpbrk(strings[i - 1], delim);
		// Set position of delim as '\0' and assign it to next character
		*strings[i] ++ = '\0';
	}
	return strings;
}


int isNA(char *test) {
	// if on Mac, '\n' will appear at test[1] instead of test[0]
	return (test[0] == '\n' || strlen(test) == 0);
}


FitbitData *importData(FILE *infile, const int lengthlimit, const char *delim) {
	// For each line
	char string[100] = "";
	char **elements = NULL;
	// For fitbitdata
	FitbitData *data;
	data = malloc(1440 * sizeof(FitbitData));
	int Fitbit_Counter = 0;

	// Skip the header
	fgets(string, lengthlimit, infile);

	// Read a line at once
	while (fgets(string, lengthlimit, infile) != NULL) {
		elements = strsplit(string, delim);
		// Write minute and check if is a NA value
		strcpy(data[Fitbit_Counter].minute,
			isNA(elements[0]) ? "NA" : elements[0]);
		// Write calories and check if is a NA value
		data[Fitbit_Counter].calories = isNA(elements[1]) ? -1.0 : atof(elements[1]);
		// Write distance and check if is a NA value
		data[Fitbit_Counter].distance = isNA(elements[2]) ? -1.0 : atof(elements[2]);
		// Write floors and check if is a NA value
		data[Fitbit_Counter].floors = isNA(elements[3]) ? -1 : atoi(elements[3]);
		// Write heartRate and check if is a NA value
		data[Fitbit_Counter].heartRate = isNA(elements[4]) ? -1 : atoi(elements[4]);
		// Write steps and check if is a NA value
		data[Fitbit_Counter].steps = isNA(elements[5]) ? -1 : atoi(elements[5]);
		// Write sleep levels and check if is a NA value
		data[Fitbit_Counter].sleepLevel = isNA(elements[6]) ? 0 : atoi(elements[6]);
		Fitbit_Counter++;
	}
	return data;
}


double getSumCal(FitbitData *data) {
	double sum = 0;
	for (int i = 0; i < 1440; i++)
		sum += data[i].calories;
	return sum;
}


double getSumDist(FitbitData *data) {
	double sum = 0;
	for (int i = 0; i < 1440; i++)
		sum += data[i].distance;
	return sum;
}


int getSumFloor(FitbitData *data) {
	int sum = 0;
	for (int i = 0; i < 1440; i++)
		sum += data[i].floors;
	return sum;
}


int getSumStep(FitbitData *data) {
	int sum = 0;
	for (int i = 0; i < 1440; i++)
		sum += data[i].steps;
	return sum;
}


double getAvgHR(FitbitData *data) {
	int sum = 0, count = 0;
	for (int i = 0; i < 1440; i++) {
		if (data[i].heartRate == -1)
			continue;
		sum += data[i].heartRate;
		count++;
	}
	return sum / (double) count;
}


int getMaxStep(FitbitData *data) {
	unsigned int max = 0x00000000;
	for (int i = 0; i < 1440; i++) {
		if (data[i].steps > max)
			max = data[i].steps;
	}
	return max;
}


char **getPoorSleep(FitbitData *data) {
	int poorIndex = 0,
		poorTemp = 0;
	//char **range = malloc(sizeof(char*) * 2); //work for Mac only
	static char *range[2] = { NULL }; // why can't use without static?

	char *stTemp = data[0].minute;
	for (int i = 0; i < 1440; i++) {
		// In the range of poor sleep
		if (data[i].sleepLevel > 1) {
			poorTemp += data[i].sleepLevel;
			// Exit the poor sleep
		} else {
			// If is poorer than ever
			if (poorTemp > poorIndex) {
				poorIndex = poorTemp;
				range[0] = stTemp;
				range[1] = data[i - 1].minute;
			}
			poorTemp = 0;
			stTemp = data[i + 1].minute;
			continue;
		}
	}
	return range;
}


void exportResult(FILE *out, FitbitData *data) {
	char ** range = getPoorSleep(data);
	char value[500];
	printf("\nResult : \n");
	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fputs("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n", out);
	sprintf(value, "%.2f,%.2f,%d,%d,%.2f,%d,%s:%s\n",
		getSumCal(data),
		getSumDist(data),
		getSumFloor(data),
		getSumStep(data),
		getAvgHR(data),
		getMaxStep(data),
		range[0], range[1]);
	printf("%s\n", value);
	fputs(value, out);
}
