/*
Programming Assignment 2
Date : Jan 29, 2018
Names : Chun-Peng James Chen
Instructure : Andrew O'Fallon
TA : Alexandar Lao
Description : This program allow users to manage their playlist in command-line
environment
*/

#ifndef functions_h
#define functions_h

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h> // Mac
// # include <windows.h> // Windows

typedef struct duration {
  int Minutes;
  int Secondes;
} Duration;


typedef struct record {
  char Artist[100];
  char Album_title[100];
  char Song_title[100];
  char Genre[100];
  Duration Song_length;
  int Number_times_played;
  int Rating;
} Record;


typedef struct node {
  Record data;
  struct node *pNext;
  struct node *pPrev;
} Node;

// Inspect the list;
void inspectList(Node *playlist, char *msg);
// Clear the screen
void clearScreen();
// Pause for user's response to proceed
void Stop();
// Display menu, take and return the user's option
int displayMenu();
// Perform user's option, will check if any file loaded when needed
void doOption(int option, Node **playlist, int *isLoaded);
// Load the data from file and store in playlist
int doLoad(Node **playlist, char *file);
// Split a string into a string array by the delim
char ** strsplit(char *input, int size, const char *delim);
// Convert a string array into a record struct
Record *getRecord(char **elements);
// Make new node that contain input record
Node *makeNode(Record record);
// Insert new not at front, return 1 if succeed
int insertFront(Node **playlist, Record record);
// Store the current playlist into a file
void doStore(Node *playlist);
// Display the content of playlist
void doDisplay(Node *playlist);
// Print list by artist
void printList(Node *playlist, int option, char *artist);
// Prompt users to input the new song
void doInsert(Node **playlist);
// Prompt users to input a song they'd like to delete
void doDelete(Node **playlist);
// Delete the node by its artist's name
int deleteNodeByName(Node **playlist, char *name);
// Perform sorting
void doSort(Node **playlist);
// Perform insertion sorting
void sortByOption(Node **playlist, int option);
// Allow user to edit the record
void doEdit(Node *playlist);
// Subsetting the linked list, return the subset
Node *subList(Node *playlist, char *artist, int selected[]);
// check if the list contain more than one record
int isMoreThanOne(Node *playlist);
// Edit the selected node
void editNodeN(Node *playlist, int selected);
// Edit the rating in the specific record
void doRate(Node *playlist);
// Display the song
void doPlay(Node *playlist);
// Pause program for a sec
void pauseOneSec();
// Showing song information of the node
void playSong(Node *playlist);
// Randomly display song information without replacement
void doShuffle(Node *playlist);
// Get the size of list
int getSize(Node *playlist);
// Generate a series of random number without replacement
int *getRdmInts(int size);

#endif /* functions_h */
