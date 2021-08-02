/*********************************
* Class: MAGSHIMIM C1			 *
* Week 7           				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define LOWER 0
#define UPPER 172486
/*
Bug Report: 
1. LOWER and UPPER weren't used in a printf function where they could've
2. announcing variables should be before printf's lines 57-58
3. line 60 while instead of if
*/
void welcome(void);
void useage(void);
void getNumber(void);
void printTwice(int number);

int main(void)
{
	welcome();
	return 0;
}

/*
This function prints "welcome".
input: none
output: none
*/
void welcome(void)
{
	printf("Welcome to my cool program!\n");
	useage();
}

/*
This function prints what the program is for.
input: none
output: none
*/
void useage(void)
{
	printf("My program gets a number from you - and prints it twice in a row!\n");
	getNumber();
}

/*
The function gets a number.
input: none
output: none
*/
void getNumber(void)
{
	int number = 0;
	printf("Please enter a number between %d - %d: \n", LOWER, UPPER);
	scanf("%d", &number);
	if(number < LOWER || number > UPPER)
	{
		printf("Invalid choice!\n");
		scanf("%d", &number);
	}
	printTwice(number);
}


/*
Prints the number twice. 
input: the number we got from the user.
output: none
*/
void printTwice(int number)
{
	printf("The number twice in a row: %d%d", number, number);
}