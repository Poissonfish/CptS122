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

/*************************************************************
 * Function: run_app ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/

void run_app (void)
{
	/* Need these file handles to keep track of the input and output files. */
	FILE *infile = NULL, *outfile = NULL;

	/* Declare variables to store complete records. Recall that this program reads
	   5 records from an input file. Thus, we need 5 variables of each field in the
	   record. Note: each record contains an id number field, gpa field,
	   class standing field, and age field. The number appended to the end of
	   each variable indicates which record it belongs to. */

	/* Stores the ID number field of the record. */
	int id1 = 0, id2 = 0, id3 = 0, id4 = 0, id5 = 0;

	/* Stores the gpa field of the record. */
	double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0;

	/* Stores the class standing field of the record. */
	int class1 = 0, class2 = 0, class3 = 0, class4 = 0, class5 = 0;

	/* Stores the age field of the record. */
	double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;

	/* Stores individual sums needed to calculate the means. */
	double sum_gpas = 0.0, sum_class_standings = 0.0, sum_ages = 0.0;

	/* Stores individual means. */
	double mean_gpas = 0.0, mean_class_standings = 0.0, mean_ages = 0.0;

	/* Store deviations of gpas. */
	double gpa1_dev = 0.0, gpa2_dev = 0.0, gpa3_dev = 0.0, gpa4_dev = 0.0, gpa5_dev = 0.0;

	/* Stores the variance and standard deviation of the gpas. */
	double gpa_variance = 0.0, gpa_standard_dev = 0.0;

	/* Store the gpa min and max */
	double gpa_min = 0.0, gpa_max = 0.0;
	
	/* Open the input and output files before accessing them */
	infile = fopen ("input.dat", "r");
	outfile = fopen ("output.dat", "w");

	/* Could not open input file. May be because do not have read permissions
	   or the file does not exist, etc. */
	if (infile == NULL) 
	{
		printf ("Could not open input file %s for reading!\n", "input.dat");
		printf ("Exiting!\n");
		exit (1); /* Exit the program completely! */
	}

	/* Could not open output file. May be because do not have write permissions
	   or the disk is full and cannot create a new file, etc. */
	if (outfile == NULL)
	{
		printf ("Could not open output file %s for writing!\n", "output.dat");
		printf ("Exiting!\n");
		exit (1); /* Exit the program completely! */
	}

	/* Read in the first record from the input file. Recall the each record has 
	   the following:
		- ID # as an int
		- GPA as a double
		- Class standing as an int
		- Age as a double */
	id1 = read_integer (infile);
	gpa1 = read_double (infile);
	class1 = read_integer (infile);
	age1 = read_double (infile);

	/* Read in the second record from the input file. */ 
	id2 = read_integer (infile);
	gpa2 = read_double (infile);
	class2 = read_integer (infile);
	age2 = read_double (infile);

	/* Read in the third record from the input file. */ 
	id3 = read_integer (infile);
	gpa3 = read_double (infile);
	class3 = read_integer (infile);
	age3 = read_double (infile);

	/* Read in the fourth record from the input file. */ 
	id4 = read_integer (infile);
	gpa4 = read_double (infile);
	class4 = read_integer (infile);
	age4 = read_double (infile);

	/* Read in the fifth record from the input file. */ 
	id5 = read_integer (infile);
	gpa5 = read_double (infile);
	class5 = read_integer (infile);
	age5 = read_double (infile);

	/* Calculate the sums of all the gpas, class standings, and ages of each record. */
	sum_gpas = calculate_sum (gpa1, gpa2, gpa3, gpa4, gpa5);
	sum_class_standings = calculate_sum (class1, class2, class3, class4, class5);
	sum_ages = calculate_sum (age1, age2, age3, age4, age5);

	/* Calculate the means of the gpas, class standings, and ages of each record. */
	mean_gpas = calculate_mean (sum_gpas, 5);
	mean_class_standings = calculate_mean (sum_class_standings, 5);
	mean_ages = calculate_mean (sum_ages, 5);

	/* Write the means of gpas, class standings, and ages to the output file. */
	print_double (outfile, mean_gpas);
	print_double (outfile, mean_class_standings);
	print_double (outfile, mean_ages);
	fputc ('\n', outfile);

	/* Calculate the deviation of each of the 5 gpas. */
	gpa1_dev = calculate_deviation (gpa1, mean_gpas);
	gpa2_dev = calculate_deviation (gpa2, mean_gpas);
	gpa3_dev = calculate_deviation (gpa3, mean_gpas);
	gpa4_dev = calculate_deviation (gpa4, mean_gpas);
	gpa5_dev = calculate_deviation (gpa5, mean_gpas);

	/* Determine the variance of the gpas. */
	gpa_variance = calculate_variance (gpa1_dev, gpa2_dev, gpa3_dev, gpa4_dev, gpa5_dev, 5);

	/* Determine the standard deviation of the gpas. */
	gpa_standard_dev = calculate_standard_deviation (gpa_variance);

	/* Determine the min and the max of the gpas. */
	gpa_min = find_min (gpa1, gpa2, gpa3, gpa4, gpa5);
	gpa_max = find_max (gpa1, gpa2, gpa3, gpa4, gpa5);

	/* Write the standard deviation, min, and max of the gpas to the output file. */
	print_double (outfile, gpa_standard_dev);
	print_double (outfile, gpa_min);
	print_double (outfile, gpa_max);

	/* Close the input and output files */
	fclose (infile);
	fclose (outfile);
}

/*************************************************************
 * Function: read_double ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function reads one double from an       *
 *              input file.                                  *
 * Input parameters: An input file pointer.                  *
 * Returns: A double precision value.                        *
 * Preconditions: The input file must already be open.       *
 * Postconditions: A copy of the double precision value      *
 *                 read in from the file is returned.        *
 *************************************************************/

double read_double (FILE *infile)
{
	double number = 0.0;

	fscanf (infile, "%lf", &number); /* Read in the double precision number */

	return number;
}

/*************************************************************
 * Function: read_integer ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function reads one integer from an      *
 *              input file.                                  *
 * Input parameters: An input file pointer.                  *
 * Returns: A integer value.                                 *
 * Preconditions: The input file must already be open.       *
 * Postconditions: A copy of the integer value               *
 *                 read in from the file is returned.        *
 *************************************************************/

int read_integer (FILE *infile)
{
	int number = 0;

	fscanf (infile, "%d", &number); /* Read in the integer number */

	return number;
}

/*************************************************************
 * Function: calculate_sum ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function calculates the sum of 5        *
 *              numbers.                                     *
 * Input parameters: The 5 numbers to sum.                   *
 * Returns: The sum.                                         *
 * Preconditions: Each number has a value.                   *
 * Postconditions:                                           *
 *************************************************************/

double calculate_sum (double number1, double number2, double number3, 
					  double number4, double number5)
{
	double sum = 0.0;

	sum = number1 + number2 + number3 + number4 + number5;

	return sum;
}
/*************************************************************
 * Function: calculate_mean ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function calculates the mean.           *
 * Input parameters: The sum and the number to average.      *
 * Returns: The mean.                                        *
 * Preconditions: The sum has been calculated.               *
 * Postconditions:                                           *
 *************************************************************/

double calculate_mean (double sum, int number)
{
	double mean = 0.0;

	mean = sum / ((double) number);

	return mean;
}

/*************************************************************
 * Function: calculate_deviation ()                          *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function calculates the dev as          *
 *              the number - mean.                           *
 * Input parameters: The number and the mean.                *
 * Returns: The deviation of the number.                     *
 * Preconditions: The mean has been calculated.              *
 * Postconditions:                                           *
 *************************************************************/

double calculate_deviation (double number, double mean)
{
	double deviation = 0.0;

	deviation = number - mean;

	return deviation;
}

/*************************************************************
 * Function: calculate_variance ()                           *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function calculates the variance of 5   *
 *              numbers.                                     *
 * Input parameters: The deviation of each number.           *
 * Returns: The variacne.                                    *
 * Preconditions: The deviations of each number have been    *
 *                calculated.                                *
 * Postconditions:                                           *
 *************************************************************/

double calculate_variance (double deviation1, double deviation2, double deviation3, 
						   double deviation4, double deviation5, int number)
{
	double variance = 0.0, sum = 0.0;

	sum = calculate_sum ((deviation1 * deviation1), (deviation2 * deviation2),
		                 (deviation3 * deviation3), (deviation4 * deviation4),
				         (deviation5 * deviation5));

	variance = calculate_mean (sum, number);

	return variance;
}

/*************************************************************
 * Function: calculate_standard_deviation ()                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function calculates the std dev as      *
 *              the sqrt(variance).                          *
 * Input parameters: The variance.                           *
 * Returns: The std dev.                                     *
 * Preconditions: The variance has been calculated.          *
 * Postconditions:                                           *
 *************************************************************/

double calculate_standard_deviation (double variance)
{
	double standard_deviation = 0.0;

	standard_deviation = sqrt (variance);

	return standard_deviation;
}

/*************************************************************
 * Function: find_max ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function finds the largest number.      *
 * Input parameters: 5 double precision numbers.             *
 * Returns: Largest value out of the 5 numbers.              *
 * Preconditions: 5 numbers have been read from the file.    *
 * Postconditions:                                           *
 *************************************************************/

double find_max (double number1, double number2, double number3, double number4, double number5)
{
	double result = number1;

	if (result < number2)
	{
		result = number2;
	}
	if (result < number3)
	{
		result = number3;
	}
	if (result < number4)
	{
		result = number4;
	}
	if (result < number5)
	{
		result = number5;
	}

	return result;
}

/*************************************************************
 * Function: find_min ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function finds the smallest number.     *
 * Input parameters: 5 double precision numbers.             *
 * Returns: Smallest value out of the 5 numbers.             *
 * Preconditions: 5 numbers have been read from the file.    *
 * Postconditions:                                           *
 *************************************************************/

double find_min (double number1, double number2, double number3, double number4, double number5)
{
	double result = number1;

	if (result > number2)
	{
		result = number2;
	}
	if (result > number3)
	{
		result = number3;
	}
	if (result > number4)
	{
		result = number4;
	}
	if (result > number5)
	{
		result = number5;
	}

	return result;
}

/*************************************************************
 * Function: print_double ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: This function prints a double to a file.     *
 * Input parameters: The file pointer, outfile, and the      *
 *                   double value, number.                   *
 * Returns: Nothing.                                         *
 * Preconditions: The output file must be open.              *
 * Postconditions: A double value is written to the output   *
 *                 file.                                     *
 *************************************************************/

void print_double (FILE *outfile, double number)
{
	printf ("Writing %.2lf to %s...\n", number, "output.dat");
	fprintf (outfile, "%0.2lf\n", number); /* Write a double precision value
										      to the hundredths place to an output file. */
}