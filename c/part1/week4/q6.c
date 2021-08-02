#include <stdio.h>

#define YEAR 2020

int main()
{
	int bornYear = 0;
	int chosenNum = 1;
	
	printf("Enter the first letter: ");
	char firstLetter = getchar();
	getchar();
	printf("\nEnter the second letter: ");
	char secondLetter = getchar();
	getchar();
	printf("\nEnter the third letter: ");
	char thirdLetter = getchar();
	getchar();
	
	printf("\nThe name is: %c%c%c\n", firstLetter, secondLetter, thirdLetter);
	
	printf("What year were you born? ");
	scanf("%d", &bornYear);
	printf("\nChoose a number between 1 and 100 ");
	scanf("%d", &chosenNum);
	
	int age = YEAR-bornYear;
	
	printf("You are %d years old", age);
	printf("\n%d %% %d = %d", age, chosenNum, age%chosenNum);
	
	return 0;
}