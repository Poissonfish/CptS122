/*
Programming Assignment 2
Date : Jan 29, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program allow users to manage their playlist in command-line
environment
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
