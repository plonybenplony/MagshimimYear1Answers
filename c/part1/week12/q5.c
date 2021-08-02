#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char findMostCommonLetter(char str[], char ignore);
void swap(char str[], char a, char b);

int main()
{
	char str[MAX_LEN];
	char mostCommon = ' ';
	char secondMostCommon = ' ';
	
	int max = 0;
	int second = 0;
	
	printf("Enter a string: ");
	fgets(str, MAX_LEN, stdin);
	
	mostCommon = findMostCommonLetter(str, ' ');
	secondMostCommon = findMostCommonLetter(str, mostCommon);
	
	printf("Most common: %c, 2nd most common: %c\n", mostCommon, secondMostCommon);
	
	printf("swapped:\n%");
	swap(str, mostCommon, secondMostCommon);
	
	return 0;
}

char findMostCommonLetter(char str[], char ignore)
{
	char find = ' ';
	int max = 0;
	
	for (int l=0; l<26; l++)
	{
		for (int i=0, n=0; i<strlen(str); i++)
		{
			
			if (str[i] == l+97 && str[i] != ignore)
			{
				n++;
				if (n > max)
				{
					find = str[i];
					max = n;
				}
			}
			
		}
	}
	
	return find;
}

void swap(char str[], char a, char b)
{
	for (int i=0; i<strlen(str); i++)
	{
		if (str[i] == a)
			str[i] = b;
		else if (str[i] == b)
			str[i] = a;
	}
	
	printf("%s", str);
}