#include <stdio.h>

int main()
{
	int n = 0;
	int sum = 0;
	
	printf("Please enter a number\n");
	scanf("%d", &n);
	
	for(int i=1; i<=9; i++)
	{
		int j = 1;
		do
		{
			j*=10;
			
			if(n%j/(j/10) == i)
			{
				sum += i;
				break;
			}
		}
		while(j<n);
	}
	
	printf("Sum of different digits is %d", sum);
	
	return 0;
}