#include <stdlib.h>
#include <stdio.h>

int main()
{
	int a = 65;
	char c = (char)a;
	int m = 3.0/2;
		
	printf("%c\n", c);				// output: A
	printf("%f\n", (float)a);   	// output: 65.000000
	printf("%f !!!!!!!!!!!!!!!!!!!!!!\n", 5.0 / 2);
	printf("%f\n", 5.0 / 2);		// output: 2.5000000
	printf("%f\n", 5 / 2.0);		// output: 2.5000000
	printf("%f\n", (float)5 / 2); 	// output: 2.5000000
	printf("%f\n", 5 / (float)2); 	// output: 2.5000000
	printf("%f\n", (float)(5 / 2)); // output: 2.0000000
	printf("%f\n", 5.0 / 2); 		// output: 2.5000000
	printf("%d\n", m); 				// output: 1

	return(0);
}
