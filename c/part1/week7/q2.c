#include <stdio.h>

int main()
{
	int maxNum = 0;
	int secondMaxNum = 0;
	
	int i = 0;
	int n = 0;
	do
	{
		printf("Enter number (-999 to stop): ");
		scanf("%d", &n);
		if(n > maxNum || i==0)
		{
			secondMaxNum = maxNum;
			maxNum = n;
		}
		else if(n > secondMaxNum && n < maxNum || i==0)
			secondMaxNum = n;
		
		i++;
	}
	while(n != -999);
	
	printf("First max: %d, Second max: %d", maxNum, secondMaxNum);
	
	return 0;
}