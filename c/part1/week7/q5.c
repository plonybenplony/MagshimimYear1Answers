#include <stdio.h>

int main()
{
	int n1 = 0;
	int n2 = 0;
	
	printf("Write the first number\n");
	scanf("%d", &n1);
	printf("Write the second number\n");
	scanf("%d", &n2);
	
	if(n1==n2)
		printf("The result is %d", n1);
	
	int mul = n1 * n2;
	int dist = (n1 > n2)?n1-n2 : n2-n1;
	
	if(mul % dist == 0)
		printf("The result is %d", mul / dist);
	else
		printf("The result is %d", mul);
	
	return 0;
}