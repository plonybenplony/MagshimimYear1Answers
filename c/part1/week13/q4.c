#include <stdio.h>
#include <string.h>

#define ABC_COUNT 26

#define MAX_WORDS 10
#define MAX_LEN 20

int checkForPangram(char words[][MAX_LEN]);
void removeEnters(char word[]);

int main()
{
	char words[MAX_WORDS][MAX_LEN] = {0};
	
	printf("Enter up to 10 words, try to make a  pangram:\n");
	for (int i=0; i<MAX_WORDS; i++) // getting words
	{
		fgets(words[i], MAX_LEN, stdin);
		removeEnters(words[i]);
		
		if (checkForPangram(words))
		{
			printf("It's a pangram?\nYes!");
			return 0;
		}
	}
	
	printf("It's a pangram?\nNo");
	return 0;
}

int checkForPangram(char words[][MAX_LEN])
{
	for(int i=0; i<ABC_COUNT; i++) // letter in the abc
	{
		int exist = 0;
		for(int w=0; w<MAX_WORDS && !exist; w++) // word from words
		{
			for(int c=0; c<MAX_LEN && !exist; c++) // character from word
			{
				if (97+i == words[w][c])
					exist = 1;
				
			}
		}
		if (!exist)
			return 0;
	}
	
	return 1;
}

void removeEnters(char word[])
{
	for (int i=0; i<MAX_LEN; i++)
	{
		if (word[i] == '\n')
			word[i] = '\0';
	}
}