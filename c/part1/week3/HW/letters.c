#include <stdio.h>

int main()
{
	char a = 'a';
	char z = 'z';
	
	//I subtruct the letter 'a' from the letter 'z' and print it as int after printing the letters
	printf("the letters are '%c' and '%c', and the amount of letters in the english abc is %d", a, z, z-a+1);
}
