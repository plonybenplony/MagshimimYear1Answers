#include <stdio.h>

int main()
{
	const float PI = 3.14;
	
	float radius = 0.0;
	printf("enter a radius for the sphere\n");
	scanf("%f", &radius);
	
	float volume = (radius*radius*radius)*(PI)*4/3; // some of the parenthesis are for the aesthetics
	
	printf("the radius that was entered is: %f cm\n", radius);
	printf("the volume of the sphere is: %f cm\n", volume);
	
	return 0;
}