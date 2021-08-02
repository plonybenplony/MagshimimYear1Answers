#include <stdio.h>
#include <math.h>

void printSmallerRoots(int n);

int main(void)
{
	int n = 0;

	printf("Enter a number: ");
	(void)scanf("%d", &n);
	(void)getchar();

	printf("All squares less than %d:\n", n);

	printSmallerRoots(25);

	(void)getchar();
	return 0;
}

/*
the time the function printSmallerRoots takes is O(sqrt(n))
*/

void printSmallerRoots(int n)
{
	float nRoot = sqrt(n);

	for (int i = 1; i < nRoot; i++)
	{
		printf("%d ", i*i);
	}
}