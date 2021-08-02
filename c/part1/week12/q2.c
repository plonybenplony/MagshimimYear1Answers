#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void reverseString(char array[]);

int main()
{
	int n = 0;
	int nCopy = 0;
	char str[MAX_LEN] = {0};
	
	printf("Enter num: ");
	scanf("%d", &n);
	nCopy = n;
	
	if (n < 0)
		n*=-1;
	
	int i = strlen(str) - 1;
	int j = 1;
	do
	{
		j*=10;
		i++;
		
		//printf("%d", n%j/(j/10));
		str[i] = n%j/(j/10) + 48;
	}
	while(j<n);
	
	if (nCopy > 0)
		str[i+1] = '+';
	else if (nCopy < 0)
		str[i+1] = '-';
	
	reverseString(str);
	
	printf("string: %s length: %d\n", str, strlen(str));
	
	return 0;
}

void reverseString(char array[])
{
	char newArray[strlen(array)];
	
	for (int i=0; i < strlen(array); i++)
		newArray[i] = array[strlen(array) - i - 1];
	
	for (int i=0; i < strlen(array); i++)
		array[i] = newArray[i];
}