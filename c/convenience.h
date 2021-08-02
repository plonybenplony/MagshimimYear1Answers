#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define NULL 0

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
typedef char* string;

void getStr(char str[], int size)
{
	fgets(str, size, stdin);
	*(str + strcspn(str, "\n")) = '\0';
	*(str + size - 1) = '\0';
}

char* getStr(int size)
{
	char str[size];
	fgets(str, size, stdin);
	*(str + strcspn(str, "\n")) = '\0';
	*(str + size - 1) = '\0';

	return str;
}

int getInt()
{
	int x = 0;
	scanf("%d", &x);
	return x;
}

int getfloat()
{
	float x = 0;
	scanf("%f", &x);
	return x;
}

void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int arrcmp(void* arr1, void* arr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*(arr1 + i) != *(arr2 + i))
			return 0;
	}
	
	return 1;
}

int random(int min, int max)
{
	int r = 0;

#ifdef BETTER_RNG
	srand(time(NULL) * &r);
#else
	srand(time(NULL));
#endif

	int r = (rand() % (max - min)) + min;
	
	return r;
}