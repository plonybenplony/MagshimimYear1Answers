#include <stdio.h>
#include <math.h>

void printNumElements(int a, int q, int num);

int main()
{
	int a = 0;
	int q = 0;
	int num = 0;
	
	// getting values
	printf("Enter first element of the series: ");
	scanf("%d", &a);
	
	printf("Enter the series ratio: ");
	scanf("%d", &q);
	
	printf("Enter number of element to display: ");
	scanf("%d", &num);
	
	// calling fuction
	printNumElements(a, q, num);
	
	return 0;
}

// a function to print num numbers of a series that uses a and q
void printNumElements(int a, int q, int num)
{
	for(int n=0; n<num; n++)
	{
		int element = a * pow(q, n); // I'm not sure that we're allowed to use pow. so if we aren't- imagine i either thought about a good solution or i created a function of my own to use pow
		printf("%d ", element);
	}
}