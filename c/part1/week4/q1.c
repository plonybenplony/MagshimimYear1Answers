#include <stdio.h>

int main()
{
	char firstLetter = 'H';
	
	printf("enter a letter\n");
	char secondLetter = getchar();
	
	getchar();
	
	char thirdLetter = 'a';
	printf("enter a letter\n");
	scanf("%c", &thirdLetter);
	
	//the first variable and the first letter+1
	printf("the first letter: %c, the first letter+1: %c\n", firstLetter, firstLetter+1);
	//the first variables number value
	printf("the first letters number value is: %d\n", firstLetter);
	//the sum of the three variables as a number
	printf("the sum of the three letters as a number is: %d\n", firstLetter+secondLetter+thirdLetter);
	//the sum of the first and last variables as a number
	printf("the sum of the first and last letters as a number: %d\n", firstLetter+thirdLetter);
	//the sum of the first and last variables as a letter
	printf("the sum of the first and last letters as a letter: %c\n", firstLetter+thirdLetter);
	
	
	return 0;
}