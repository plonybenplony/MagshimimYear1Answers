#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exists(const char* fname);

int main(int argc, char** argv)
{
	if (argc < 4)
	{
		printf("Invalid execution.\n");
		printf("Usage: prog.exe (textCopy|binaryCopy) <sourceFilename_filename> <destFilenameination_filename>\n");
		return -1;
	}

	if (!exists(argv[2]))
	{
		printf("%s file does not exist.\n", argv[2]);
		return -1;
	}
	if (exists(argv[3]))
	{
		int choice = 0;
		printf("Do you want to overwrite? 0 (no) / 1 (yes)\n");
		(void)scanf("%d", &choice);
		if (!choice)
			return -1;
	}

	FILE* src;
	FILE* dst;

	if (!strcmp(argv[1], "textCopy"))
	{
		src = fopen(argv[2], "r");
		dst = fopen(argv[3], "w");

		char ch = fgetc(src);
		while (ch != EOF)
		{
			fputc(ch, dst);
			ch = fgetc(src);
		}
	}
	else if (!strcmp(argv[1], "binaryCopy"))
	{
		src = fopen(argv[2], "rb");
		dst = fopen(argv[3], "wb");

		unsigned int n, m;
		unsigned char buffer[8192];
		do
		{
			n = fread(buffer, 1, sizeof buffer, src);
			if (n) m = fwrite(buffer, 1, n, dst);
			else   m = 0;
		} while ((n > 0) && (n == m));
		if (m) return -1;
	}
	else
	{
		printf("%s\n", argv[1]);
		printf("Invalid execution.\n");
		printf("Usage: prog.exe (textCopy|binaryCopy) <sourceFilename_filename> <destFilenameination_filename>\n");
		return -1;
	}

	printf("Copy completed\n");

	fclose(src);
	fclose(dst);


	(void)getchar();
	(void)getchar();
	return 0;
}

int exists(const char* fname)
{
	FILE* file;
	if ((file = fopen(fname, "r")))
	{
		fclose(file);
		return 1;
	}
	return 0;
}