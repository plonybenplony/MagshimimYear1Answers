#include <stdio.h>

int main()
{
	int celsius = 10;
	
	float fahrenheit = (float)celsius * 9.0 / 5.0 + 32.0;
	
	printf("celsius: %d, fahrenheit: %.2f\n", celsius, fahrenheit);
	
	return 0;
}