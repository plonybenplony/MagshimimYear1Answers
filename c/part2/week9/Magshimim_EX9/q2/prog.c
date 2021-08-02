#include <stdio.h>

#define USE_MEMO 1
#define MAX_MEM_SIZE 512

int fibonacci(int i, int mem[MAX_MEM_SIZE]);
int count = 0;

int main(void)
{
	int mem[MAX_MEM_SIZE] = { 0 };

	/*for (int i = 0; i < 20; i++)
	{
		printf("%d - %d\n", i, fibonacci(i, mem));
	}*/

	printf("%d - %d\n", 5, fibonacci(5, mem));
	printf("count: %d\n", count); count = 0;
	printf("%d - %d\n", 7, fibonacci(7, mem));
	printf("count: %d\n", count); count = 0;

	(void)getchar();
	return 0;
}

int fibonacci(int i, int mem[MAX_MEM_SIZE])
{
	count++;

#if USE_MEMO
	if (mem[i] != 0)
		return mem[i];
#endif
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
#if USE_MEMO
	mem[i] = fibonacci(i - 1, mem) + fibonacci(i - 2, mem);
	return mem[i];
#else
	return fibonacci(i - 1, mem) + fibonacci(i - 2, mem);
#endif
}