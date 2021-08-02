#include <stdio.h>
#include <string.h>

#define NAME_LEN 10
#define NAMES_COUNT 10

void printShorest(char names[][NAME_LEN]);
void printLongest(char names[][NAME_LEN]);
void printFirst(char names[][NAME_LEN]);
void printLast(char names[][NAME_LEN]);

int main()
{
	char names[NAMES_COUNT][NAME_LEN] = {0};
	
	printf("Enter 10 names:\n");
	for (int i=0; i<NAMES_COUNT; i++) // getting names
		fgets(names[i], NAME_LEN, stdin);
	
	for (int i=0; i<NAMES_COUNT; i++) // removing \n's
	{
		for (int j=0; j<NAME_LEN; j++)
		{
			if (names[i][j] == '\n')
				names[i][j] = '\0';
		}
	}
	
	printf("\n"); // Spacing things...
	
	printShorest(names);
	printLongest(names);
	printFirst(names);
	printLast(names);
	
	return 0;
}

void printShorest(char names[][NAME_LEN])
{
	int min = 11;
	int index = -1;
	
	for(int i=0; i<NAMES_COUNT; i++)
	{
		if (strlen(names[i]) < min)
		{
			min = strlen(names[i]);
			index = i;
		}
	}
	
	printf("Shortest: %s\n", names[index]);
}

void printLongest(char names[][NAME_LEN])
{
	int max = 0;
	int index = -1;
	
	for(int i=0; i<NAMES_COUNT; i++)
	{
		if (strlen(names[i]) > max)
		{
			max = strlen(names[i]);
			index = i;
		}
	}
	
	printf("Longest: %s\n", names[index]);
}

void printFirst(char names[][NAME_LEN])
{
	char first[NAME_LEN] = "zzz";
	
	for (int i=0; i<NAMES_COUNT; i++)
	{
		for(int j=0; j<NAME_LEN; j++)
		{
			if (names[i][j] < first[j])
			{
				for (int c=0; c<NAME_LEN; c++)
					first[c] = names[i][c];
				break;
			}
			if (names[i][j] > first[j])
				break;
		}
	}
	
	printf("First: %s\n", first);
}

void printLast(char names[][NAME_LEN])
{
	char last[NAME_LEN] = "AAA";
	
	for (int i=0; i<NAMES_COUNT; i++)
	{
		for(int j=0; j<NAME_LEN; j++)
		{
			if (names[i][j] > last[j])
			{
				for (int c=0; c<NAME_LEN; c++)
					last[c] = names[i][c];
				break;
			}
			if (names[i][j] < last[j])
				break;
		}
	}
	
	printf("Last: %s\n", last);
}