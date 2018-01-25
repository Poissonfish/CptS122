/*******************************************************************************
 * Programmer: Andrew S. O'Fallon                                              *
 * Class: CptS 121; Lab Section 0                                              *
 * Programming Assignment: Example                                             *
 * Date:                                                                       *
 *                                                                             *
 * Description: This program calculates statistics on student records          *
 *              read in from a file.                                           *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (input.dat): 12345678 (ID int)               *
 *                                             3.78     (gpa double)           *
 *									           3        (class standing int)   *
 *									           20.5     (age double)           *
 *                                                                             *
 * Format of output file (output.dat): See problem specification.              *
 ******************************************************************************/

#include "example.h"

int main (void)
{
	run_app ();

	return 0;
}



/*
1.    Minute
2.    Calories
3.    Distance (in miles)
4.    Floors
5.    Heartrate
6.    Steps
7.    Sleep level

-	   You must open �FitbitData.csv� for mode read; check for success

-      You must read each record in the file as a string, one line at a time using fgets()

-      You must parse each record using strtok() from <string.h> into the corresponding fields, and store into the FitbitData array; note: not all fields have values, some are �empty� or null

-      You must compute the total calories burned, distance walked in miles, floors walked, and steps taken

-      You must compute average heartrate over the 24 hour period

-      You must report the max steps taken in one minute over the 24 hour period; if there are multiple minutes throughout the day where the max is discovered, then report the one that is the latest in the 24 hour period

-      You must report the longest consecutive range of poor sleep; a range is defined as one or more consecutive minutes where the sleepLevel > 1; the poorest sleep is not based on the length of the range, but the sum of the sleep levels in the range; the max sum of the ranges is considered the poorest sleep (report the starting and ending minutes of range)

-      You must open �Results.csv� for mode write; this will either create a new .csv or overwrite an existing one

-      You must output two lines to �Results.csv� and to the screen in the following format:

o   Line 1: Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep

o   Line 2: valueCalories,valueDistance,valueFloors,valueSteps,valueHeartrate,valueMax,valueSleepStart:valueSleepEnd

-      You must close �FitbitData.csv� and �Results.csv�
*/
