/*
Programming Assignment 1
Date : Jan 24, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program read a csv file and compute the descriptive statistics,
then export the results to another csv file.
*/

#ifndef functions_h
#define functions_h

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

/*
Open file and check if open successfully
*/
FILE * openFile(char* name, char* mode);

/*
Close file
*/
void closeFile(FILE *file);

/*
Split a string into a string array
*/
char ** strsplit(char *input, const char *delim);

/*
Check if the string contain no value
*/
int isNA(char *test);

/*
Parse data from file to a struct and return it
*/
FitbitData *importData(FILE *infile, const int lengthlimit, const char *delim);

/*
Get sum of calories burned
*/
double getSumCal(FitbitData *data);

/*
Get sum of distance walked
*/
double getSumDist(FitbitData *data);

/*
Get sum of floors taken
*/
int getSumFloor(FitbitData *data);

/*
Get sum of steps taken
*/
int getSumStep(FitbitData *data);

/*
Get average of heartrate
*/
double getAvgHR(FitbitData *data);

/*
Get the max step taken
*/
int getMaxStep(FitbitData *data);

/*
Get the duration of the poorest sleep
*/
char **getPoorSleep(FitbitData *data);

/*
Compute the values and export them into a file
*/
void exportResult(FILE *out, FitbitData *data);

#endif /* functions_h */
