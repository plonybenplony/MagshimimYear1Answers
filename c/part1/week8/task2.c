#include <stdio.h>

void addAndPrint(int n1, int n2)
{
	printf("%d\n", n1 + n2);
}

void subAndPrint(int n1, int n2)
{
	addAndPrint(n1-n2, 0);
}

int main()
{
	int n1 = 0;
	int n2 = 0;
	
	printf("Enter two numbers\n");
	scanf("%d", &n1);
	scanf("%d", &n2);
	printf("\n");
	
	addAndPrint(n1, n2);
	subAndPrint(n1, n2);
	
	return 0;
}