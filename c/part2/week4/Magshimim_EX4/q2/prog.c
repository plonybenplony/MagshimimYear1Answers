#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int length);

int main(void)
{
	int length = 0;

	printf("Enter length of array: ");
	(void)scanf("%d", &length);

	int* arr = malloc(length * sizeof(int));

	printf("Enter %d numbers:\n", length);
	for (int i = 0; i < length; i++)
	{
		(void)scanf("%d", arr + i);
	}

	sort(arr, length);

	printf("Sorted:\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", *(arr + i));
	}

	free(arr);

	(void)getchar();
	(void)getchar();
	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void sort(int* arr, int length)
{
	qsort(arr, length, sizeof(int), compare);
}