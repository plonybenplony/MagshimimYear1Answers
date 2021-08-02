#include <stdio.h>

int main()
{
	int cousin1 = 25;
	int cousin2 = 23;
	int cousin3 = 21;
	
	int grandma = 72;
	int grandpa = 75;
	
	int cousinsAgeTogether = cousin1+cousin2+cousin3;
	int grandParentsAgeTogether = grandma + grandpa;
	
	printf("Cousins ages are: %d %d %d.\n", cousin1, cousin2, cousin3);
	printf("Grand parents ages are: grandma- %d, grandpa- %d.\n", grandma, grandpa);
	printf("Cousins age together is: %d.\n", cousinsAgeTogether);
	printf("Grand parents age together is: %d.\n", grandParentsAgeTogether);
	
	return 0;
}