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
  Node *playlist = NULL;
  int option = 0, isLoaded = 0;
  while (option != 11) {
		clearScreen();
    option = displayMenu();
    doOption(option, &playlist, &isLoaded);
  }
	printf("Program ends\n");
}
