#include <stdio.h>

int main()
{
	int a = 53, b = 12;
	
	printf("a = %d, b = %d\n", a, b);
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	printf("a = %d, b = %d\n", a, b);
	
	return 0;
}