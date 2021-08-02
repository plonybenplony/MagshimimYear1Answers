#include <stdio.h>
#include <string.h>

#define MAX_SIZE 128

void decrypt(char* cipher, int n);

int main(void)
{
	char cipher[MAX_SIZE] = "";
	int key = 0;

	printf("Enter cipher to decrypt: ");
	gets(cipher);
	printf("Enter decryption key: ");
	(void)scanf("%d", &key);

	decrypt(cipher, key);

	(void)getchar();
	(void)getchar();
	return 0;
}

void decrypt(char* cipher, int n)
{
	_strrev(cipher);

	for (int i = 0; i < strlen(cipher); i++)
	{
		*(cipher + i) += n;
		*(cipher + i) = ((*(cipher + i) - 97) % 26) + 97;
	}

	printf("Decrypted text: %s", cipher);
}