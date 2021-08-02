/*********************************
* Class: MAGSHIMIM C1			 *
* Week 11        				 *
* MagshiParty					 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define NUM_GUESTS 200
#define MAX_AGE_KIDS_MEAL 12
/*#define FALSE 	0
#define TRUE !FALSE*/
// I don't need those, they will just interfere

void printsAndCalls(int ages[], int size);
float averageAge(int ages[], int size);
int kidsMeal(int ages[], int size);
int ageExistance(int ages[], int size, int age);
int couplesFinder(int ages[], int size, int age);
int findYoungest(int ages[], int size);
int findOldest(int ages[], int size);

int main(void)
{
	int guestAges[NUM_GUESTS] = {42, 108, 95, 101, 90, 5, 79, 79, 83, 105, 66, 66, 2, 28, 2, 12, 116, 63, 28, 37,	
					 112, 85, 63, 34, 53, 23, 22, 117, 39, 96, 48, 7, 12, 19, 70, 113, 108, 20, 116,
					 55, 24, 52, 3, 94, 34, 105, 22, 32, 54, 29, 108, 45, 23, 118, 118, 20, 84, 22,
					 50, 59, 77, 36, 111, 43, 49, 107, 41, 63, 65, 89, 87, 46, 51, 10, 11, 111, 7, 22,
					 34, 69, 70, 24, 85, 35, 37, 81, 47, 57, 12, 29, 25, 40, 27, 44, 18, 59, 39, 43, 
					 10, 102, 34, 36, 80, 19, 25, 91, 100, 27, 114, 67, 102, 66, 45, 113, 31, 70, 18, 
					 94, 58, 73, 107, 91, 42, 37, 36, 48, 16, 95, 72, 53, 111, 71, 22, 5, 47, 71, 28, 
					 72, 8, 58, 98, 48, 34, 64, 66, 30, 50, 39, 102, 109, 63, 107, 27, 71, 94, 9,
					 61, 72, 43, 96, 11, 120, 25, 18, 69, 4, 116, 82, 3, 111, 92, 117, 15, 101, 37, 22, 
					 109, 40, 109, 5, 2, 55, 54, 80, 19, 99, 61, 69, 8, 108, 9, 14, 49, 44, 48, 22, 
					 31, 18, 14, 35};
	
	printsAndCalls(guestAges, NUM_GUESTS);
	
	return 0;
}

void printsAndCalls(int ages[], int size)
{
	printf("Average age: %.2f\n", averageAge(ages, size));
	
	printf("Number of kids %d and under: %d\n", MAX_AGE_KIDS_MEAL, kidsMeal(ages, size));
	
	int ageToSearch = 0;
	printf("Enter age to search: ");
	scanf("%d", &ageToSearch);
	if (ageExistance(ages, size, ageToSearch))
	{
		printf("Guest found!\n");
	}else
	{
		printf("No guest this age.\n");
	}
	
	printf("Enter age of guest looking for friend: ");
	scanf("%d", &ageToSearch);
	if (couplesFinder(ages, size, ageToSearch))
	{
		printf("A couple in the same age was found!\n");
	}else
	{
		printf("No couples found...\n");
	}
	
	printf("Youngest guest age: %d\n", findYoungest(ages, size));
	
	printf("Oldest guest age: %d\n", findOldest(ages, size));
}

float averageAge(int ages[], int size)
{
	float avg = 0;
	float sum = 0;
	
	for (int i=0; i<size; i++)
	{
		sum += ages[i];
	}
	
	avg = sum / size;
	
	return avg;
}

int kidsMeal(int ages[], int size)
{
	int count = 0;
	
	for (int i=0; i<size; i++)
	{
		if (ages[i] <= MAX_AGE_KIDS_MEAL)
		{
			count++;
		}
	}
	
	return count;
}

int ageExistance(int ages[], int size, int age)
{
	for (int i=0; i<size; i++)
	{
		if (ages[i] == age)
		{
			return 1;
		}
	}
	
	return 0;
}

int couplesFinder(int ages[], int size, int age)
{
	short count = 0; // short because the biggest value will be 2...
	
	for (int i=0; i<size; i++)
	{
		if (ages[i] == age)
		{
			count++;
			if (count >= 2)
			{
				return 1;
			}
		}
	}
	
	return 0;
}

int findYoungest(int ages[], int size)
{
	int y = ages[0];
	
	for (int i=0; i<size; i++)
	{
		if (ages[i] < y)
		{
			y = ages[i];
		}
	}
	
	return y;
}

int findOldest(int ages[], int size)
{
	int o = ages[0];
	
	for (int i=0; i<size; i++)
	{
		if (ages[i] > o)
		{
			o = ages[i];
		}
	}
	
	return o;
}



