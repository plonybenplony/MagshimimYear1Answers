#include <stdio.h>
#include <conio.h>

int main()
{
	printf("Do you want to be a Magshim? y/n\n");
	
	char answer = getchar();
	
	printf("your answer is: ");
	
	putchar(answer);
	
	return 0;
}