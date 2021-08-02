#include <stdio.h>

int main()
{
	const int MAX_NUM = 1000;
	
	int count = 0;
	
	for (int i = 2; i <= MAX_NUM; i++)
	{
		int dividors = 0;
		for(int j = 1;j <= i;j++)
        {
            if(i%j==0)
                dividors++;
        }
		if(dividors==2)
        {
            printf("Prime number: %d\n",i);
			count++;
        }
	}
	
	printf("Num of primes: %d\n", count);
	
	return 0;
}