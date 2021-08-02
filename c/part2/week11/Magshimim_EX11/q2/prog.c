#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function(int a, int b);
void functionOptimized(int a, int b);

int main(void)
{
	int a = 0;
	int b = 0;

	printf("enter a number a\n");
	(void)scanf("%d", &a);
	(void)getchar();
	printf("enter a smaller number b\n");
	(void)scanf("%d", &b);
	(void)getchar();

	functionOptimized(a, b);

	(void)getchar();
	return 0;
}

// the time complexity of this function is O(n-m)
// Function gets two numbers ([a]>[b]) and prints all the numbers from [a] to [b] that are divisors of [b]
void function(int a, int b)
{
	int i = 0;
	for (i = a; i >= b; i--)
	{
		if (i % b == 0)
		{
			printf("%d ", i);
		}
	}
}

// Function gets two numbers ([a]>[b]) and prints all the numbers from [a] to [b] that are divisors of [b]
void functionOptimized(int a, int b)
{
	int i = 0;
	for (i = a-(a%b); i >= b; i-=3)
	{
		printf("%d ", i);
	}
}