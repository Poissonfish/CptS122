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


void clearScreen() {
	system("clear"); // For MacOS
	// system("CLS"); // For Windows
}


void Stop() {
	printf("\n<Press Enter to Continue>\n");
	getchar();
	getchar();
}


int displayMenu() {
		// Declaration
    int option = 0;
		// Print welcom message and menu
		printf("Hi, welcome to my playlist manager!\n");
		printf("Please input an option: \n");
    printf("(1) load\n");
    printf("(2) store\n");
    printf("(3) display\n");
    printf("(4) insert\n");
    printf("(5) delete\n");
    printf("(6) edit\n");
    printf("(7) sort\n");
    printf("(8) rate\n");
    printf("(9) play\n");
    printf("(10) shuffle\n");
    printf("(11) exit\n");
		// Get users' input
    scanf("%d", &option);
    return option;
}


void doOption(int option, Node **playlist, int *isLoaded) {
	if (option == 1)
		*isLoaded = doLoad(playlist);
	else if (*isLoaded)
		switch(option) {
	    case 2:
		   	doStore(*playlist);
	      break;
	    case 3:
	      doDisplay(*playlist);
	      break;
	    // case 4:
	    //   doInsert();
	    //   break;
	    // case 5:
	    //   doDelete();
	    //   break;
	    case 6:
	      doEdit(*playlist);
	      break;
	    // case 7:
	    //   doSort();
	    //   break;
	    case 8:
	      doRate(*playlist);
	      break;
	    case 9:
	      doPlay(*playlist);
	      break;
	    // case 10:
	    //   doShuffle();
	    //   break;
	    case 11:
				clearScreen();
	      printf("Good bye!\n");
				break;
	    default:
	      printf("Invalid option!\n");
				Stop();
				break;
		}
	else {
		printf("You haven't loaded any file yet!\n");
		Stop();
	}
}


int doLoad(Node **playlist) {
	clearScreen();
	printf("Loading...");
	// Declaration
  FILE *infile = NULL;
  char string[1000] = "";
  char **elements = NULL;
	int success = 0;
	Record *record = NULL;
	// Open file
	infile = fopen("/Users/jameschen/Dropbox/GradSchool/*Spring_18/CPTS_122/PA2/musicPlayList.csv", "r");
	if (infile != NULL) {
		success = 1;
		// Read lines in file to a string
		while (fgets(string, 1000, infile) != NULL && success == 1) {
			// Split a string into 7 elements
			elements = strsplit(string, 7, ",");
			// Extract elements to struct record
			record = getRecord(elements);
			// Insert the record to the list
			success = insertFront(playlist, *record);
		}
		// close file
		fclose(infile);
		printf("Done!\n");
	} else {
		printf("\nFile not found!\n");
		exit(0);
	}
	Stop();
	return success;
}


char ** strsplit(char *input, int size, const char *delim) {
	// Allocate memory in heap(permanent) instad of stack(temporary)
	char **strings = malloc(sizeof(char*) * size);
	// Get pointer from input string
	strings[0] = input;
	for (int i = 1; i < size; i++) {
		// Escape artist name with double quote
		if (strings[i - 1][0] == '"') {
			// Get position of delim from last start point
			strings[i - 1] ++;
			strings[i] = strpbrk(strings[i - 1], "\"");
			*strings[i] ++ = '\0';
		} else {
			// Get position of delim from last start point (i - 1)
			strings[i] = strpbrk(strings[i - 1], delim);
		}
		// Set position of delim as '\0' and assign it to next character
		*strings[i] ++ = '\0';
	}
	return strings;
}


Record *getRecord(char **elements) {
	// Declaration
	char **songLength = { NULL };
  Record *record = NULL;
  record = (Record *) malloc(sizeof(Record));
	// Extract elements
	if (record != NULL) {
		strcpy(record->Artist, elements[0]);
	  strcpy(record->Album_title, elements[1]);
	  strcpy(record->Song_title, elements[2]);
	  strcpy(record->Genre, elements[3]);
		songLength = strsplit(elements[4], 2, ":");
	  record->Song_length.Minutes = atoi(songLength[0]);
	  record->Song_length.Secondes = atoi(songLength[1]);
	  record->Number_times_played = atoi(elements[5]);
	  record->Rating = atoi(elements[6]);
	}
  return record;
}


Node *makeNode(Record record) {
	// Declaration
  Node *node = NULL;
	// Allocate memeory for the node
  node = (Node *) malloc(sizeof(Node));
	// If allocate memory for node
	if (node != NULL) {
		node->pPrev = NULL;
	  node->data = record;
	  node->pNext = NULL;
	}
	return node;
}


int insertFront(Node **playlist, Record record) {
	// Declaration
	int success = 0;
	Node *pNew = makeNode(record);
	if (pNew != NULL) {
		// Not an empty list
		if (*playlist != NULL) {
			pNew->pNext = *playlist;
			(*playlist)->pPrev = pNew;
			*playlist = pNew;
		// An empty list
		} else {
			*playlist = pNew;
		}
		success = 1;
	} else
		printf("Invalid record\n");
	return success;
}


void doStore(Node *playlist) {
	clearScreen();
	printf("Storing...");
	// Declaration
	FILE *outfile = NULL;
	char string[100] = "";
	// Open file
	outfile = fopen("musicPlayList.csv", "w");
	// If is a valid list
	while (playlist != NULL) {
		// Put it into a string, add double quote for the first column wihch would likely contain comma
		sprintf(string, "\"%s\",\"%s\",\"%s\",%s,%d:%d,%d,%d\n",
									playlist->data.Artist,
									playlist->data.Album_title,
									playlist->data.Song_title,
									playlist->data.Genre,
									playlist->data.Song_length.Minutes,
									playlist->data.Song_length.Secondes,
									playlist->data.Number_times_played,
									playlist->data.Rating);
		// Put the string into file
		fputs(string, outfile);
		// Point to next list
		playlist = playlist->pNext;
	}
	printf("done\n");
	fclose(outfile);
	Stop();
}


void doDisplay(Node *playlist) {
	int option = 0;
	char name[100] = "";
	printf("Print all or by the artist?\n");
	printf("(1) Print all records.\n");
	printf("(2) Print all records that match an artist.\n");
	scanf("%d", &option);
	switch(option) {
		case 1:
			clearScreen();
			printf("Your playlist:\n");
			printList(playlist, option, NULL);
			break;
		case 2:
			printf("Please input an artist name: ");
			scanf(" %[^\n]", name);
			clearScreen();
			printf("Your playlist:\n");
			printList(playlist, option, name);
			break;
	}
	Stop();
}


void printList(Node *playlist, int option, char *artist) {
	int index = 1;
	printf("%8s%20s%22s%17s%10s%6s%3s%17s%9s\n",
					"Index", "Artist", "Album", "Song", "Genre",
					"Len", "gth", "NumberTimePlayed", "Rating");
	switch (option) {
		case 1:
			do {
				//Index
				printf("%7d.", index++);
				//Artist
				printf("%20s", playlist->data.Artist);
				//Album
				printf("%22s", playlist->data.Album_title);
				//Song
				printf("%17s", playlist->data.Song_title);
				//Genre
				printf("%10s", playlist->data.Genre);
				//Length
				printf("%6d:%2d", playlist->data.Song_length.Minutes,
														playlist->data.Song_length.Secondes);
				//NumberTimePlayed
				printf("%17d", playlist->data.Number_times_played);
				//Rating
				printf("%9d\n", playlist->data.Rating);
				//Next list
				playlist = playlist->pNext;
			} while(playlist != NULL);
			break;
		case 2:
			do {
				if(strcmp(playlist->data.Artist, artist) == 0) {
					//Index
					printf("%7d.", index++);
					//Artist
					printf("%20s", playlist->data.Artist);
					//Album
					printf("%22s", playlist->data.Album_title);
					//Song
					printf("%17s", playlist->data.Song_title);
					//Genre
					printf("%10s", playlist->data.Genre);
					//Length
					printf("%6d:%2d", playlist->data.Song_length.Minutes,
															playlist->data.Song_length.Secondes);
					//NumberTimePlayed
					printf("%17d", playlist->data.Number_times_played);
					//Rating
					printf("%9d\n", playlist->data.Rating);
				}
				//Next list
				playlist = playlist->pNext;
			} while(playlist != NULL);
			break;
	}
}


void doEdit(Node *playlist) {
	clearScreen();
	// Declaration
	char artist[100] = "";
	Node *sub = NULL;
	int option = 0, selectedFinal = 0;;
	int selected[100];
	// Ask for name
	printf("Your playlist : \n");
	printList(playlist, 1, NULL);
	printf("\nEnter an artist you want to edit: ");
	scanf(" %[^\n]", artist);
	// Subset the list
	sub = subList(playlist, artist, selected);
	// If can't find a match
	printf("\n");
	if (sub == NULL) {
		printf("Can't find a match artist!\n");
	} else {
		// Find more than one match
		if (isMoreThanOne(sub)) {
			clearScreen();
			printf("There're more than one record found: \n");
			printList(sub, 1, NULL);
			printf("\nInput an index number for one you'd like to edit (Starts from 1): ");
			scanf("%d", &option);
			selectedFinal = selected[option - 1];
			printf("\n");
		// Find only one match
		} else {
			selectedFinal = selected[0];
		}
		editNodeN(playlist, selectedFinal);
	}
	printf("\nThe specified record has been edited!");
	Stop();
}


Node *subList(Node *playlist, char *artist, int selected[]) {
	Node *sub = NULL;
	int count = 1, index = 0;
	do {
		if(strcmp(playlist->data.Artist, artist) == 0){
			insertFront(&sub, playlist->data);
			// Catch the selected index
			selected[index ++] = count;
		}
		//Next list
		playlist = playlist->pNext;
		count ++;
	} while(playlist != NULL);
	return sub;
}


int isMoreThanOne(Node *playlist) {
	if (playlist->pNext == NULL)
		return 0;
	return 1;
}


void editNodeN(Node *playlist, int selected) {
	// Declaration
	int option = 0;
	char editString[100];
	int editRate = 0;
	Record *selectedPtr = NULL;
	for (int i = 1; i < selected; i ++)
		playlist = playlist->pNext;
	selectedPtr = &(playlist->data);
	printf("Which attribute you'd like to edit:\n");
	printf("\t(1) Artist\n");
	printf("\t(2) Album title\n");
	printf("\t(3) Song title\n");
	printf("\t(4) Genre\n");
	printf("\t(5) Rating\n");
	printf("Enter a number to specify an attribute (1~5) : ");
	scanf(" %d", &option);
	printf("\n");
	switch(option) {
		case 1:
			printf("Current artist's name is   : %s\n", (*selectedPtr).Artist);
			printf("You'd like to change it to : ");
			scanf(" %[^\n]", editString);
			strcpy((*selectedPtr).Artist, editString);
			break;
		case 2:
			printf("Current album's name is    : %s\n", (*selectedPtr).Album_title);
			printf("You'd like to change it to : ");
			scanf(" %[^\n]", editString);
			strcpy((*selectedPtr).Album_title, editString);
			break;
		case 3:
			printf("Current song's name is     : %s\n", (*selectedPtr).Song_title);
			printf("You'd like to change it to : ");
			scanf(" %[^\n]", editString);
			strcpy((*selectedPtr).Song_title, editString);
			break;
		case 4:
			printf("Current shown genre is     : %s\n", (*selectedPtr).Genre);
			printf("You'd like to change it to : ");
			scanf(" %[^\n]", editString);
			strcpy((*selectedPtr).Genre, editString);
			break;
		case 5:
			printf("Current rating or this song: %d\n", (*selectedPtr).Rating);
			printf("You'd like to change it to : ");
			scanf("%d", &editRate);
			(*selectedPtr).Rating = editRate;
			break;
	}
}


void doRate(Node *playlist) {
	clearScreen();
	// Declaration
	int option = 0;
	Record *selectedPtr = NULL;
	printf("Your playlist : \n");
	printList(playlist, 1, NULL);
	printf("\nWhich song you'd like to change its rating?\n");
	printf("Please enter a number to specify the song (Starts from 1): ");
	scanf("%d", &option);
	for (int i = 1; i < option; i ++)
		playlist = playlist->pNext;
	selectedPtr = &(playlist->data);
	printf("Current rating or this song: %d\n", (*selectedPtr).Rating);
	printf("You'd like to change it to : ");
	scanf("%d", &option);
	(*selectedPtr).Rating = option;
	printf("\nThe specified record has been edited!");
	Stop();
}


void doPlay(Node *playlist) {
	clearScreen();
	// Declaration
	int option = 0;
	Node *pBeginning = playlist,
			 *pPlay = NULL;
	printf("Your playlist : \n");
	printList(playlist, 1, NULL);
	printf("\nWhich song you'd like to play?\n");
	printf("Please enter a number to specify the song (Starts from 1): ");
	scanf("%d", &option);
	for (int i = 1; i < option; i ++)
		playlist = playlist->pNext;
	pPlay = playlist;
	do {
		clearScreen();
		printf("Now it's playing ... \n");
		printf("Artist : %s\n", playlist->data.Artist);
		printf("Album  : %s\n", playlist->data.Album_title);
		printf("Song   : %s\n", playlist->data.Song_title);
		printf("Genre  : %s\n", playlist->data.Genre);
		printf("Rating : %d\n", playlist->data.Rating);
		usleep(1000000);
		if ((playlist->pNext) == NULL)
			playlist = pBeginning;
		else
			playlist = playlist->pNext;
	} while(playlist != pPlay);
	printf("\n");
	Stop();
}
