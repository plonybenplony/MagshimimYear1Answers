#include <stdio.h>

int main()
{
	printf("Enter the first letter: ");
	char firstLetter = getchar();
	getchar();
	printf("Enter the second letter: ");
	char secondLetter = getchar();
	getchar();
	printf("Enter the third letter: ");
	char thirdLetter = getchar();
	getchar();
	
	printf("The name is: %c%c%c", firstLetter, secondLetter, thirdLetter);
	
	return 0;
}