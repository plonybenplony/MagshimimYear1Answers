#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

#define PROJ_SAVE_SEPERATOR ";"
#define PROJ_SAVE_SEPERATOR_NEWLINE ";\n"

// Function gets a head of a linked list and a path, and saves the list in the path
void saveproj(FrameNode** head, const char* path);

// Function gets a head of a linked list and a real path to a saved project, and loads the file to the list
void loadproj(FrameNode** head, const char* path);

// Functions gets a string and a number and returns the [num] part of the string seprated by [PROJ_SAVE_SEPERATOR]
char* splitstr(char* str, int num);

// Function gets a head of a linked list and returns a string representing the given list
char* totext(FrameNode** head);

// ------------------------Utility functions needed for this file------------------------

// Function gets a string and returns a new string from index [beg] to index [end] in the new string
char* substr(const char* str, int beg, int end);

// Functions takes two c strings ([dest] has to be on the heap), and adds the second string to the first one, it's also reallocating memory
void strcat_heap(char** dest, const char* src);

// Function get an int and returns it's length is it was a string (8 - 1, 27 - 2, 159 - 3)
unsigned int intlen(int n);

#endif