#define _CRT_SECURE_NO_WARNINGS

#include "view.h"
#include "linkedList.h"
#include "saveload.h"

#include <stdio.h>
#include <stdlib.h>


const char* MENU = "\nWhat would you like to do?\n\
 [0] Exit\n\
 [1] Add new frame\n\
 [2] Remove a frame\n\
 [3] Change frame's index\n\
 [4] Change frame's duration\n\
 [5] Change duration for all frames\n\
 [6] List frames\n\
 [7] Play GIF (press [Esc] to stop)\n\
 [8] Save project\n\
 [9] Export to a .gif file\n";

void getStr(char str[], int size);
void clearbuff();
void loadexisting(FrameNode** head);
void option1(FrameNode** head);
void option2(FrameNode** head);
void option3(FrameNode** head);
void option4(FrameNode** head);
void option5(FrameNode** head);
void option6(FrameNode** head);
void option7(FrameNode** head);
void option8(FrameNode** head);
void option9(FrameNode** head);

int main(void)
{
	FrameNode* head = NULL;
	int opt = -1;

	// Greet
	printf("Welcome to Eitan's GIF maker!\n");

	// Load project
	opt = intput_range("What would you like to do?\n [0] Create a new project\n [1] Load existing project\n", 0, 1);
	if (opt == 1)
		loadexisting(&head);
	else
		printf("Creating a new project!\n");

	opt = -1;
	// Main loop
	while (opt != 0)
	{
		printf(MENU);
		(void)scanf("%d", &opt);
		clearbuff();

		switch (opt)
		{
		case 0:
			printf("Bye\n"); break;
		case 1:
			option1(&head); break;
		case 2:
			option2(&head); break;
		case 3:
			option3(&head); break;
		case 4:
			option4(&head); break;
		case 5:
			option5(&head); break;
		case 6:
			option6(&head); break;
		case 7:
			option7(&head); break;
		case 8:
			option8(&head); break;
		case 9:
			option9(&head); break;
		default:
			printf("Option is Invalid\n");  break;
		}
	}

	deletelist(&head);

	(void)getchar();
	return 0;
}

// Gets all necessary inputs and loads an existing project into [head]
void loadexisting(FrameNode** head)
{
	char projpath[MAX_STR_LEN] = "";

	printf("Enter the path to the project:\n");
	getStr(projpath, MAX_STR_LEN);
	FILE* a = NULL;
	if (!(a = fopen(projpath, "r"))) { printf("Given path is invalid\n"); return; } fclose(a); // Check the given path

	loadproj(head, projpath);

	printf("Successfully loaded the project\n");
}

// Gets all necessary inputs and adds a node to the given list
void option1(FrameNode** head)
{
	char path[MAX_STR_LEN] = "";
	unsigned int dur = 0;
	char name[MAX_STR_LEN] = "";

	// Greet
	printf("-----Creating a new frame!-----\n");

	// Getting the path to the image
	printf("Enter the image path:\n");
	getStr(path, MAX_STR_LEN);

	// Getting the duration for the frame
	printf("Enter the duration (in milliseconds):\n");
	(void)scanf("%u", &dur);
	clearbuff();

	// Getting the name for the frame
	printf("Enter a name:\n");
	getStr(name, MAX_STR_LEN);
	// Cheking it's availability
	while (searchlist(*head, name))
	{
		printf("Name is taken\nEnter a name:\n");
		getStr(name, MAX_STR_LEN);
	}

	// Call the actual function
	addframe(head, newframenode_props(name, dur, path));

	printf("Successfully added a new frame\n");
}

// Gets all necessary inputs and removes a node to the given list
void option2(FrameNode** head)
{
	unsigned int length = lstlen(*head);
	unsigned int delframe = length+1;

	// Greet
	printf("-----Removing a frame!-----\n");

	// Validate length
	if (length < 1) { printf("Can't remove a frame if there are no frames\n"); return; }

	// Get frame index
	while (delframe > length || delframe < 1)
	{
		printf("Which frame would you want to remove? (1-%u)\n", length);
		(void)scanf("%u", &delframe);
	}
	clearbuff();

	// Print success
	if (lstpopindex(head, delframe - 1))
		printf("Successfully removed the %u%s frame\n", delframe, delframe == 1 ? "st" : (delframe == 2 ? "nd" : (delframe == 3 ? "rd" : "th")));
	else
		printf("Couldn't remove the selected frame\n");
}

// Gets all necessary inputs and changes chosen node's index of the given list
void option3(FrameNode** head)
{
	unsigned int length = lstlen(*head);
	char tomove[MAX_STR_LEN] = "";
	unsigned int tomoveindex = 0;
	unsigned int newindex = 0;

	// Greet!
	printf("-----Moving a frame!-----\n");

	// Check length
	if (length < 2) { printf("Not Enough frames to change order\n"); return; }

	// Get the name (check validity)
	printf("Which frame would you like to move? (Enter a name)\n");
	getStr(tomove, MAX_STR_LEN);
	while ( (tomoveindex = searchlist(*head, tomove)) == 0 )
	{
		printf("Frame doesn't exist\nWhich frame would you like to move? (Enter a valid name)\n");
		getStr(tomove, MAX_STR_LEN);
	}
	tomoveindex--;

	// Get the new index (check validity)
	printf("Where do you want to move the frame to? (1-%u)\n", length);
	(void)scanf("%u", &newindex);
	while (newindex < 1 || newindex > length)
	{
		printf("Index must be real\nWhere do you want to move the frame to? (1-%u)\n", length);
		(void)scanf("%u", &newindex);
	}
	newindex--;
	clearbuff();

	// Call the actual function
	changenodeindex(head, tomoveindex, newindex);

	printf("Successfully moved a frame\n");
}

// Gets all necessary inputs and changes chosen frame's duration
void option4(FrameNode** head)
{
	char framename[MAX_STR_LEN] = "";
	unsigned int newdur = 0;

	printf("-----Changing frame's duration!-----\n");

	// Get the name (check validity)
	printf("Which frame's duration would you like to change? (Enter a name)\n");
	getStr(framename, MAX_STR_LEN);
	while (!searchlist(*head, framename))
	{
		printf("Frame doesn't exist\nWhich frame's duration would you like to change? (Enter a valid name)\n");
		getStr(framename, MAX_STR_LEN);
	}

	// Get the new wanted duration
	printf("What is the new duration you want?\n");
	(void)scanf("%u", &newdur);
	clearbuff();

	// Change the duration
	(*getnode(head, framename))->frame->duration = newdur;

	printf("Successfully changed %s's duration to %u\n", framename, newdur);
}

// Gets all necessary inputs and changes all the durations from all frames
void option5(FrameNode** head)
{
	unsigned int newdur = 0;
	unsigned int length = lstlen(*head);

	// Greet
	printf("-----Changing all durations!-----\n");

	// Get the new wanted duration
	printf("What is the new duration you want?\n");
	(void)scanf("%u", &newdur);
	clearbuff();

	for (unsigned int i = 0; i < length; i++)
	{
		(*getnodeindex(head, i))->frame->duration = newdur;
	}

	printf("Successfully changed all durations to %u\n", newdur);
}

// Prints the list
void option6(FrameNode** head)
{
	printf("-----Printing the GIF!-----\n\n");

	printf("\tName:\t\t\tDuration:\t\t\tPath:\n");

	printList(*head);

	printf("\nSuccessfully Printed the list, %d items\n", lstlen(*head));
}

// Plays the GIF
void option7(FrameNode** head)
{
	// Greet
	printf("-----Playing the GIF!-----\n\n");

	// Remind about closing the GIF
	printf("REMEBER! - Press [Esc] to close the window!\n");

	// Getting whether or not we want it reversed
	if (intput("Do you want to see the GIF normally or reversed? (0 - normally, 1 - reversed)\n") != 0)
	{
		// reverse list
		reverselist(head);

		// playing it
		play(head);

		// de-reverse list (unreversing it)
		reverselist(head);
	}
	else
	{
		// playing it
		play(head);
	}
}

// Gets all necessary inputs and saves the list into a text file
void option8(FrameNode** head)
{
	char projpath[MAX_STR_LEN] = "";

	printf("-----Saving the project!-----\n\n");

	// Get the path
	printf("Where would you like to save the project? (example: C:\\gifmaker\\projects\\dogs.txt)\n");
	getStr(projpath, MAX_STR_LEN);
	FILE* a = NULL;
	if (!(a = fopen(projpath, "w"))) { printf("Given path is invalid\n"); return; } fclose(a); // Check the given path

	// Save the project
	saveproj(head, projpath);

	printf("Successfully saved the project!\n");
}

// Gets all necessary inputs and exports the list to a .gif file
void option9(FrameNode** head)
{
	char expto[MAX_STR_LEN] = "";
	
	// Get the path to save it in
	printf("Enter the path to put the gif in: (example- C:\\gifmaker\\horse.gif)\n");
	getStr(expto, MAX_STR_LEN);
	FILE* a = NULL;
	while (!(a = fopen(expto, "w")))
	{
		printf("Path is invalid, ");
		printf("Enter the path to put the gif in: (example- C:\\gifmaker\\horse.gif)\n");
		getStr(expto, MAX_STR_LEN);
	}

	// TODO: save it to a gif
}

// Prints a message, gets the numerical input and returns it
int intput(const char* msg)
{
	int x = 0;
	printf(msg);
	(void)scanf("%d", &x);
	clearbuff();
	return x;
}

// Prints a message, gets the numerical input and returns it also checks if the input is in given range else - repeat
int intput_range(const char* msg, int min, int max)
{
	int x = 0;
	printf(msg);
	(void)scanf("%d", &x);
	while (x < min || x > max)
	{
		printf("Invalid input: Out of range (%d-%d)!\n", min, max);
		(void)scanf("%d", &x);
	}
	clearbuff();
	return x;
}

void clearbuff()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void getStr(char str[], int size)
{
	fgets(str, size, stdin);
	*(str + strcspn(str, "\n")) = '\0';
	*(str + size - 1) = '\0';
}