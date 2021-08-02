#include <stdio.h>

#define SIZE 10

void arrayInput(int* arr, int size);
void arrayReverseOutput(int* arr, int size);

int main(void)
{
	int arr[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	arrayInput(arr, SIZE);

	arrayReverseOutput(arr, SIZE);

	(void)getchar();
	(void)getchar();
	return 0;
}

void arrayInput(int* arr, int size)
{
	printf("Enter 10 numbers: ");
	for (int i = 0; i < size; i++)
	{
		(void)scanf("%d", arr + i);
	}
}

void arrayReverseOutput(int* arr, int size)
{
	printf("The numbers in reverse order:");

	for (int i = size - 1; i >= 0; i--)
	{
		printf(" %d", *(arr + i));
	}
}