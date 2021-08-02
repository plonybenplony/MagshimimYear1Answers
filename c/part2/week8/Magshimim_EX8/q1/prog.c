#ifdef _WIN32
#include "dirent.h"
#else
#include <dirent.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QS_INFECTED_FIRST_20 2
#define QS_INFECTED_LAST_20 3

#define LOG_FILE_NAME "AntiVirusLog.txt"

void err(const char* error); // prints an error, then exits with error code -1
int filefile(const char* wherePath, const char* whatPath); // gets two file names, returns 1 if file 2 is in file 1, 0 otherwise
int filefile_fast(const char* wherePath, const char* whatPath); // gets two file names, returns 1 if file 2 is in file 1, 0 otherwise (but checks in different order)

int main(int argc, char** argv)
{
	if (argc < 3)
		err("U");

	// Print Welcome
	printf("Welcome to my Virus Scan!\n\n");
	// Properties
	printf("Folder to scan: %s\n", argv[1]);
	printf("Virus signature: %s\n", argv[2]);

	// Get & Save QuickScan option
	int quickscan = 0;
	printf("\nPress 0 for normal scan or any other key for a quick scan: ");
	(void)scanf("%d", &quickscan);
	printf("Scanning began...\n\
This process may take several minutes...\n\nScanning:\n");

	// dirent stuff (get the directory)
	DIR* d;
	struct dirent* dir;
	d = opendir(argv[1]);

	// Set logFileName
	char logFileName[128];
	strcpy(logFileName, argv[1]);
	strcat(logFileName, "/");
	strcat(logFileName, LOG_FILE_NAME);

	// Log file Stuff
	FILE* fpLogFile = fopen(logFileName, "w"); // Clearing the file
	fclose(fpLogFile); // Clearing the file
	fpLogFile = fopen(logFileName, "a");
	fputs("Anti-virus began! Welcome!\n\n", fpLogFile);
	fprintf(fpLogFile, "Folder to scan:\n%s\n", argv[1]);
	fprintf(fpLogFile, "Virus signature:\n%s\n\n", argv[2]);

	fprintf(fpLogFile, "Scanning option:\n%s\n\n", quickscan ? "Quick Scan" : "Normal Scan");

	fputs("Results:\n", fpLogFile);

	// If directory exist
	if (d)
	{
		// for every file in the directory - 
		while ((dir = readdir(d)) != NULL)
		{
			// If it's a real file (Not the filder itself or the last folder)
			if (dir->d_name[0] != '.')
			{
				// Get the full path of the file
				char buff[128];
				strcpy(buff, argv[1]);
				strcat(buff, "/");
				strcat(buff, dir->d_name);
				
				// Print stuff to output window
				printf("%s - ", buff);
				// Write stuff to log file
				fprintf(fpLogFile, "%s  ", buff);

				// if the QuickScan option is true - do a quickscan
				if (quickscan)
				{
					// Get the result into x & print the right line
					int x = 0;
					if ((x = filefile_fast(buff, argv[2])))
						switch (x)
						{
						case QS_INFECTED_FIRST_20:
							printf("Infected! (first 20%%)\n"); fprintf(fpLogFile, "Infected! (first 20%%)\n"); break;
						case QS_INFECTED_LAST_20:
							printf("Infected! (last 20%%)\n"); fprintf(fpLogFile, "Infected! (last 20%%)\n"); break;
						default:
							printf("Infected!\n"); fprintf(fpLogFile, "Infected!\n"); break;
						}
					else
					{
						printf("Clean\n");
						fprintf(fpLogFile, "Clean\n");
					}
				}
				// If the QuickScan option is false - do a normal scan & print the right line
				else
				{
					if (filefile(buff, argv[2]))
					{
						printf("Infected!\n");
						fprintf(fpLogFile, "Infected!\n");
					}
					else
					{
						printf("Clean\n");
						fprintf(fpLogFile, "Clean\n");
					}
				}
			}
		}
		closedir(d);
		fclose(fpLogFile);

		// Print closing lines things
		printf("Scan Completed.\n");
		printf("See log path for results: %s\n", logFileName);
	}

	(void)getchar();
	(void)getchar();
	return 0;
}

// Like strlen but for files
long long filelen(FILE* fp)
{
	if (fp == NULL)
		return 0;

	fseek(fp, 0, SEEK_END); // seek to end of file
	long long size = ftell(fp); // get current file pointer
	fseek(fp, 0, SEEK_SET); // seek to the begging

	return size;
}

// Like strcmp but for files (but returns the result that makse sense)
int filecmp(FILE* fpX, FILE* fpY, unsigned long long startXat)
{
	// If files are closed - return
	if (fpX == NULL || fpY == NULL)
		return 0;
	
	// get to the starting point for fpX
	fseek(fpX, startXat, SEEK_SET);

	// Initialize variables
	int cx = 0, cy = 0;

	// while the characters aren't NULL or EOF and in general are characters - 
	while ( (cx = fgetc(fpX)) && (cy = fgetc(fpY)) )
	{
		// If the signature file has ended - every character is the same in both files - return 1;
		if (feof(fpY))
			return 1;
		// If the characters aren't equal - return 0
		if (cx != cy)
			return 0;
	}

#ifdef _WIN32
	return fgetc(fpY) == EOF;
#else
	return 1;
#endif
}

// Utility function for filefile
int filefile_utl(FILE* fpBigger, FILE* fpSmaller)
{
	long long idx = 0;
	long long len = filelen(fpBigger);
	long long sml_len = filelen(fpSmaller) - 1;

	// While we have'nt reached to the end ("len - sml_len", because the signature can't appear if there's not enough space) -
	while (idx < (len - sml_len))
	{
		// Not sure if that's necessary...
		fseek(fpSmaller, 0L, SEEK_SET);
		fseek(fpBigger, 0L, SEEK_SET);

		// Compare the signature with the current character
		if (filecmp(fpBigger, fpSmaller, idx))
			return 1;

		// Increment the index
		idx++;
	}

	// If we have'nt returned anything yet - return 0
	return 0;
}

// Utility function for filefile_fast
int filefile_fast_utl(FILE* fpBigger, FILE* fpSmaller)
{
	long long idx = 0;
	long long len = filelen(fpBigger);
	long long sml_len = filelen(fpSmaller) - 1;

	// Step one - first 20%
	while (idx < (len / 5) - sml_len)
	{
		fseek(fpSmaller, 0L, SEEK_SET);
		fseek(fpBigger, 0L, SEEK_SET);

		if (filecmp(fpBigger, fpSmaller, idx))
			return QS_INFECTED_FIRST_20;

		idx++;
	}

	// Step two - last 20%
	idx = (len / 5) * 4;

	while (idx < len - sml_len)
	{
		fseek(fpSmaller, 0L, SEEK_SET);
		fseek(fpBigger, 0L, SEEK_SET);

		if (filecmp(fpBigger, fpSmaller, idx))
			return QS_INFECTED_LAST_20;

		idx++;
	}

	// Step three - middle 60%
	idx = len / 5;

	while (idx < ((len / 5) * 4) - sml_len)
	{
		fseek(fpSmaller, 0L, SEEK_SET);
		fseek(fpBigger, 0L, SEEK_SET);

		if (filecmp(fpBigger, fpSmaller, idx))
			return 1; // 1 Means somewhere in the middle

		idx++;
	}

	return 0;
}

// Like strstr but for files
int filefile(const char* wherePath, const char* whatPath)
{
	FILE* fpBigger = fopen(wherePath, "r");
	FILE* fpSmaller = fopen(whatPath, "r");

	int x = 0;

	if (fpBigger != NULL && fpSmaller != NULL)
		x = filefile_utl(fpBigger, fpSmaller);
	else
		err("U");

	fclose(fpBigger);
	fclose(fpSmaller);

	return x;
}

// Like filefile but checks first and last 20% before anything else
int filefile_fast(const char* wherePath, const char* whatPath)
{
	FILE* fpBigger = fopen(wherePath, "r");
	FILE* fpSmaller = fopen(whatPath, "r");

	int x = 0;

	if (fpBigger != NULL && fpSmaller != NULL)
		x = filefile_fast_utl(fpBigger, fpSmaller);
	else
		err("U");

	fclose(fpBigger);
	fclose(fpSmaller);

	return x;
}

void err(const char* error)
{
	if (!strcmp(error, "U"))
		error = "Usage: prog.exe <Folder to scan> <Kitten Virus Sign>\n";

	printf(error);
	exit(-1);
}