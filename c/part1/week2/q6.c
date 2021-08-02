#include <stdio.h>

int main()
{
	int bigNum = 2147483646;
	
	printf("%d\n", bigNum+1);
	bigNum += 2;
	printf("%d\n", bigNum);
	
	return 0;
}