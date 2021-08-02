#include <stdio.h>

#define SIZE 6

int* createArr();
void printArr(int* arr);

int main(void)
{
	printArr(createArr());

	/*
	this doesn't work because when the createArr() function is over
	all it's variables are deleted, so when we try to access them afterwards
	we get trash values. so we can't.
	*/

	(void)getchar();
	return 0;
}

int* createArr()
{
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6 };

	return arr;
}

void printArr(int* arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", *(arr + i));
	}
}