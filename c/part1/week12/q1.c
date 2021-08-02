#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 100

int main()
{
	char str[MAX_LIMIT];
	printf("Enter string (max length 100 chars): ");
	fgets(str, MAX_LIMIT, stdin);
	
	int palindrom = 1;
	
	for(int left=0, right=strlen(str)-2; right >= left; left++, right--)
	{
		while(str[left] == ' ')
			left++;
		while(str[right] == ' ')
			right--;
		if(str[left] != str[right])
		{
			palindrom = 0;
			break;
		}
	}
	
	if (palindrom)
		printf("Yes");
	else
		printf("No");
	
	return 0;
}