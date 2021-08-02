/*********************************
* Class: MAGSHIMIM C1			 *
* Week 12          				 *
**********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
I'm honestly not sure what is supposed to be wrong with the program,
it's combining the strings and printing them as it's seems to be needed...

I did however changed is so the initialzation of the string is as strings can be initialzed,
before he used a normal array-like initialzation with '{}' and comma's and all...

other than that- there isn't seems to be a visible problem,
maybe he tried to do something else but that wasn't specified...
*/

int main(void)
{
	char str1[] = "Hi ";
	char str2[] = "Ho";
	
	strncat(str1, str2, strlen(str1) + strlen(str2));
	
	printf("%s", str1);
	return 0;
	
}