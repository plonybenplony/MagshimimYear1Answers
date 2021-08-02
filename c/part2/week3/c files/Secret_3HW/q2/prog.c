#include <stdio.h>

#define SIZE 11

void printAfterX(int* arr, int size, int* x);

int main(void)
{
	int arr[SIZE] = { 4 ,8 ,6 ,2 ,1 ,3 ,5 ,7 ,8 ,9 ,5 };
	int offset = 0;

	printf("Please enter an offset to search in the array's address domain: ");
	(void)scanf("%d", &offset);

	printAfterX(arr, SIZE, arr + offset);

	(void)getchar();
	(void)getchar();
	return 0;
}

void printAfterX(int* arr, int size, int* x)
{
	if (x >= arr && x < arr + size)
	{
		for (x += 1; x < arr + size; x++)
		{
			printf("%d ", *x);
		}
	}
	else
	{
		printf("Not in the array.");
	}
}