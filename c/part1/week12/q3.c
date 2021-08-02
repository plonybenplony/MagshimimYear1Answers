#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int isPasswordStrong(char password[]);

int main()
{
	char password[MAX_LEN];
	
	printf("Enter a password: ");
	fgets(password, MAX_LEN, stdin);
	
	if(isPasswordStrong(password))
		printf("Yes");
	else
		printf("No");
	
	return 0;
}

int isPasswordStrong(char pass[])
{
	int len = strlen(pass);
	
	if (len > 8 || len < 6)
		return 0;
	
	char lastLetter = '\0';
	
	int hasDigit = 0;
	int hasCap = 0;
	int hasLow = 0;
	for(int i=0; i<len; i++)
	{
		if(pass[i] >= 48 && pass[i] <= 57)
			hasDigit = 1;
		else if(pass[i] >= 65 && pass[i] <= 90)
			hasCap = 1;
		else if(pass[i] >= 97 && pass[i] <= 122)
			hasLow = 1;
		
		if(pass[i] == lastLetter)
			return 0;
		
		lastLetter = pass[i];
	}
	if (!hasDigit)
		return 0;
	if (!hasCap)
		return 0;
	if (!hasLow)
		return 0;
	
	return 1;
}