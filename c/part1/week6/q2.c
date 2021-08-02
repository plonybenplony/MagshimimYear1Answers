#include <stdio.h>

int main()
{
	while(1)
	{
		int num = 0;
		int factorial = 1;
		
		do
		{
			if (num < 0) printf("invalid input!\n");
			printf("Enter number: ");
			scanf("%d", &num);
		}
		while(num < 0);
		
		for(int i=1; i<num+1; i++)
		{
			factorial *= i;
		}
		
		printf("Factorial of %d is: %d\n", num, factorial);
		
		getchar();
		printf("Would you like to try again?\nClick 'y' for yes other key for no\n");
		if (getchar() != 'y')
		{
			break;
		}
	}
	
	return 0;
}