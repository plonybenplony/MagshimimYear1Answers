#include <stdio.h>

void printJoke(int type);
int userChoice();

#define PROGRAMMING_NUM 0
#define MATH_NUM 1
#define NETWORKING_NUM 2

int main()
{
	printJoke(userChoice());
	
	return 0;
}
// Print the right joke
void printJoke(int type)
{
	switch (type)
	{
		case PROGRAMMING_NUM:
			printf("there are 10 types of people.\nthose who understand binary\nand those who can't");
			break;
		case MATH_NUM:
			printf("One of my math students is terrified of negative numbers.\nHe'll stop at nothing to avoid them.");
			break;
		case NETWORKING_NUM:
			printf("Stay at 127.0.0.1\nwear a 255.0.0.0");
			break;
		default:
			printf("Invalid Type");
	}
}

// Get users joke type
int userChoice()
{
	int type = 0;
	
	printf("Welcome to the Comedy Store!\n");
	printf("What kind of a joke would you like?\n");
	printf("Programming joke - %d\n", PROGRAMMING_NUM);
	printf("Math joke - %d\n", MATH_NUM);
	printf("Networking joke - %d\n", NETWORKING_NUM);
	
	scanf("%d", &type);
	
	return type;
	
}