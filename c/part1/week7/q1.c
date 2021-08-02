#include <stdio.h>

int main()
{
	int num = 0;
	int dividorsSum = 0;

	printf("Enter number: ");
	scanf("%d", &num);

	for (int i = 1; i < num; ++i)
	{
		if(num%i == 0)
		{
			dividorsSum += i;
		}
	}

	if (dividorsSum == num)
	{
		printf("Yes! The number is perfect\n");
	} else {
		printf("No! The number is not perfect\n");
	}

	return 0;
}