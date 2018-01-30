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
# include <unistd.h>

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


void clearScreen();
void Stop();
int displayMenu();
void doOption(int option, Node **playlist, int *isLoaded);
int doLoad(Node **playlist);
char ** strsplit(char *input, int size, const char *delim);
Record *getRecord(char **elements);
Node *makeNode(Record record);
int insertFront(Node **playlist, Record record);
void doStore(Node *playlist);
void doDisplay(Node *playlist);
void printList(Node *playlist, int option, char *artist);
void doEdit(Node *playlist);
Node *subList(Node *playlist, char *artist, int selected[]);
int isMoreThanOne(Node *playlist);
Record getChangedRecord(Record subrecord);
void editNodeN(Node *playlist, int selected);
void doRate(Node *playlist);
void doPlay(Node *playlist);

// void doInsert();
// void doDelete();
// void doSort();
// void doRate();
// void doPlay();
// void doShuffle();

#endif /* functions_h */
