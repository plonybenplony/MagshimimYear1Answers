#include <stdio.h>

int main()
{
	float a = 0;
	float b = 0;
	int action = 0;
	
	printf("enter two numbers - a and b.\n");
	scanf("%f %f", &a, &b);
	
	printf("1. adding a+b\n2. subtracting a-b\n3. multiplying a*b\n4. dividing a/b\n");
	
	printf("now choose from the above 1, 2, 3 or 4\n");
	scanf("%d", &action);
	
	switch (action)
	{
		case (1):
			printf("%.2f + %.2f = %.2f\n", a, b, a+b);
			break;
		case (2):
			printf("%.2f - %.2f = %.2f\n", a, b, a-b);
			break;
		case (3):
			printf("%.2f * %.2f = %.2f\n", a, b, a*b);
			break;
		case (4):
			if (b == 0)
			{
				printf("can't divide by zero\n");
				break;
			}
			printf("%.2f / %.2f = %.2f\n", a, b, a/b);
			break;
		default:
			printf("you've entered a wrong digit, you need to enter 1, 2, 3 or 4.\n");
			break;
	}
	
	return 0;
}