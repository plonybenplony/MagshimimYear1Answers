#include <stdio.h>

int main()
{
	int n = 0;
	
	printf("Enter a number between 1 between 100");
	scanf("%d", &n);
	
	while(n > 100 || n < 1)
	{
		printf("Enter a number between 1 between 100");
		scanf("%d", &n);
	}
	
	printf("Good job");
	
	return 0;
}
