#include <stdio.h>
#include <stdlib.h>

#define AVG_NUM 1
#define CHANGE_NUM 2
#define COUNT_NUM 3
#define PRINT_NUM 4
#define EXIT_NUM 5

void populateArr(int* arr, int length, int start);

void calcAvg(int* arr, int length);
void changeItem(int* arr, int length);
void changeLength(int* arr, int* lengthP);
void printArr(int* arr, int length);

int main(void)
{
	int length = 0;
	int option = -1;

	printf("Enter number of grades: ");
	(void)scanf("%d", &length);

	int* arr = malloc(length * sizeof(int)); // Create Arr

	populateArr(arr, length, 0);

	do
	{
		printf("1 - Calculate average\n2 - Change a grade\n3 - Change number of grades\n4 - Print grades\n5 - Exit\n");
		printf("Choose option: ");
		(void)scanf("%d", &option);

		switch (option)
		{
		case AVG_NUM:
			calcAvg(arr, length); break;
		case CHANGE_NUM:
			changeItem(arr, length); break;
		case COUNT_NUM:
			changeLength(arr, &length); break;
		case PRINT_NUM:
			printArr(arr, length); break;
		}
	} while (option != EXIT_NUM);

	free(arr);

	(void)getchar();
	(void)getchar();
	return 0;
}

int validGrade(int* grade)
{
	return (*grade <= 100 && *grade >= 0);
}
void getValid(int* item)
{
	while (!validGrade(item))
	{
		printf("Invalid grade. 0-100 only. Try again: ");
		(void)scanf("%d", item);
	}
}

void populateArr(int* arr, int length, int start)
{
	for (int i = start; i < length; i++)
	{
		printf("Enter grade %d: ", i+1);
		(void)scanf("%d", (arr + i));

		getValid(arr + i);
	}
}

// Options funcs
void calcAvg(int* arr, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += *(arr + i);
	}

	printf("The grades average is: %.2f\n", (float)sum / (float)length);
}
void changeItem(int* arr, int length)
{
	int idx = 0;

	printf("Which grade would you like to change? 1-%d: ", length);
	(void)scanf("%d", &idx);

	while (!(idx > 0 && idx <= length))
	{
		printf("Invalid choice. Try again: ");
		(void)scanf("%d", &idx);
	}

	idx--;

	printf("Enter new grade: ");
	(void)scanf("%d", arr + idx);

	getValid(arr + idx);
}
void changeLength(int* arr, int* lengthP)
{
	int oldLength = *lengthP;

	printf("Enter new number of grades: ");
	(void)scanf("%d", lengthP);

	int* temp = realloc(arr, (*lengthP) * sizeof(int));
	if (temp == NULL)
		printf("Error! realloc returned NULL!\n");
	else
		arr = temp;

	if (oldLength < *lengthP)
		populateArr(arr, *lengthP, oldLength);
}
void printArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", *(arr + i));
	}

	printf("\n");
}