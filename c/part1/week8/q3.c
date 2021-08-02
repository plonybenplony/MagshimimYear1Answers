#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void MasterFunc(int opt);
void printPitagoras(int a, int b);
void calcDistance();
void calcHypotenuse();
void calcCircle();
void calcRect(int a, int b);
void calcRectangle();
void calcSquare();

int main()
{
	int opt = 0;
	
	printf("Welcome to my calculator!\n");
	do
	{
		int opt = 0;
		
		printf("Choose option:\n");
		printf("1 - Calc distance between 2 points\n");
		printf("2 - Calc hypotenuse of triangle\n");
		printf("3 - Calc area and perimeter of circle\n");
		printf("4 - Calc area of rectangle\n");
		printf("5 - Calc area of square\n");
		printf("6 - Exit\n");
		
		scanf("%d", &opt);
		
		if (opt == 6)
			break;
		
		MasterFunc(opt);
	}
	while(opt != 6);
	
	printf("Goodbye!");
	
	return 0;
}

// The function that takes an option a calls the proper function
void MasterFunc(int opt)
{
	switch (opt)
	{
		case 1:
			calcDistance();
			break;
		case 2:
			calcHypotenuse();
			break;
		case 3:
			calcCircle();
			break;
		case 4:
			calcRectangle();
			break;
		case 5:
			calcSquare();
			break;
		default:
			printf("Invalid option");
			break;
		
	}
}

// a function that takes two numbers and uses the pitagoras law on them (and prints that)
void printPitagoras(int a, int b)
{
	float answer = sqrt(pow(a, 2) + pow(b, 2));
	printf("%.2f\n", answer);
}

// calculate rectangles
void calcRect(int a, int b)
{
	printf("%d\n", a*b);
}

// calculate distance between 2 points
void calcDistance()
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	
	printf("Enter point1 coordinates: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter point2 coordinates: ");
	scanf("%d %d", &x2, &y2);
	
	int side1 = x1 - x2;
	int side2 = y1 - y2;
	
	printf("Distance is ");
	printPitagoras(side1, side2);
}

// calculate hypotenuse
void calcHypotenuse()
{
	int a = 0;
	int b = 0;
	
	printf("Enter 2 sides of the triangle: ");
	scanf("%d %d", &a, &b);
	
	printf("Hypotenuse is ");
	printPitagoras(a, b);
}

// calculate circles properties
void calcCircle()
{
	int r = 0;
	
	printf("Enter circle radius: ");
	scanf("%d", &r);
	
	float p = PI * r * 2;
	float area = PI * pow(r, 2);
	
	printf("Perimeter: %.2f\n", p);
	printf("Area: %.2f\n", area);
}

void calcRectangle()
{
	int l = 0;
	int w = 0;
	
	printf("Enter rectangle length: ");
	scanf("%d", &l);
	printf("Enter rectangle width: ");
	scanf("%d", &w);
	
	printf("The area of the rectangle is ");
	calcRect(l, w);
}

void calcSquare()
{
	int s = 0;
	
	printf("Enter length of square side: ");
	scanf("%d", &s);
	
	printf("The area of the square is ");
	calcRect(s, s);
}