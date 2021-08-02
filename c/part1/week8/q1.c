#include <stdio.h>

void printNum(int num);

int main()
{
	int num = 6;
	printNum(num);
	return 0;
}

// A function that takes a number and prints it out
void printNum(int num)
{
	printf("%d", num);
}