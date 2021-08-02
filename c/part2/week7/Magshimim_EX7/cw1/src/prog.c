#include <stdio.h>

int main(void)
{
	FILE* file = fopen("C:/Users/user/Documents/magshimim/c/part2/week7/Magshimim_EX7/cw1/res/someFile.txt", "r");
	int ceaserKey = 8;

	char c = ' ';
	while ((c = (char)fgetc(file)) != EOF)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = ((c - ceaserKey) % 26) + 'a';

			printf("%c", c);

			(void)fgetc(file);
			(void)fgetc(file);
			(void)fgetc(file);
		}
		else
		{
			printf("%c", c);
		}
	}

	(void)getchar();
	return 0;
}