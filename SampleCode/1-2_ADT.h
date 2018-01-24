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

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdio.h>  /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <math.h>	/* Needed for sqrt ( ) */
#include <stdlib.h> /* Needed for exit ( ) */

/* Function prototypes */


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
void run_app (void);

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
double read_double (FILE *infile);

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
int read_integer (FILE *infile);

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
double calculate_sum (double number1, double number2, double number3, double number4, double number5);

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
double calculate_mean (double sum, int number);

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
double calculate_deviation (double number, double mean);

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
double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

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
double calculate_standard_deviation (double variance);

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
double find_max (double number1, double number2, double number3, double number4, double number5);

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
double find_min (double number1, double number2, double number3, double number4, double number5);

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
void print_double (FILE *outfile, double number);

#endif