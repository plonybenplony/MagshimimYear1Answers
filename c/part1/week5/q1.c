#include <stdio.h>

int main()
{
	char answer = ' ';
	printf("enter either y or n YES or NO\n");
	scanf("%c", &answer);
	
	if (answer == 'y') {
		printf("YES");
	} else if (answer == 'n') {
		printf("NO");
	} else {
		printf("FUZZY");
	}
	
	return 0;
}