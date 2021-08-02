/*#include <stdio.h>
#include <stdlib.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int* px = malloc(1 * sizeof(int));

	free(px);

	printf("Leaks: %d", _CrtDumpMemoryLeaks());
	(void)getchar();
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main()
{
	int size = 0;

	printf("Enter a size to malloc by: ");
	(void)scanf("%d", &size);

	int* px = malloc(size * sizeof(int));

	free(px);

	printf("Leaks: %d", _CrtDumpMemoryLeaks());
	(void)getchar();
	(void)getchar();
	return 0;
}