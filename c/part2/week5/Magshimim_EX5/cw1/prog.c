#include <stdio.h>
#include <string.h>

struct animal
{
	char type[30];
	char name[30];
	int age;
};

typedef struct animal animal;

void getStr(char str[], int size);
void clearBuff();
void printAnimal(animal anm);
int compAnimals(animal anm1, animal anm2);

int main(void)
{
	animal animal0;
	animal animal1;

	printf("Enter a type for animal0: ");
	getStr(animal0.type, 30);
	printf("Enter a name for animal0: ");
	getStr(animal0.name, 30);
	printf("Enter an age for animal0: ");
	(void)scanf("%d", &animal0.age);

	clearBuff();

	printf("Enter a type for animal1: ");
	getStr(animal1.type, 30);
	printf("Enter a name for animal1: ");
	getStr(animal1.name, 30);
	printf("Enter an age for animal1: ");
	(void)scanf("%d", &animal1.age);

	printAnimal(animal0);
	printAnimal(animal1);

	printf("The animals are %s\n", (compAnimals(animal0, animal1) ? "equal" : "different"));

	(void)getchar();
	(void)getchar();
	return 0;
}

void getStr(char str[], int size)
{
	fgets(str, size, stdin);
	*(str + strcspn(str, "\n")) = '\0';
	*(str + size - 1) = '\0';
}

void clearBuff()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void printAnimal(animal anm)
{
	printf("Animal:\n\ttype: %s\n\tname: %s\n\tage: %d\n\t\tsize of %s: %d\n", anm.type, anm.name, anm.age, anm.name, sizeof(anm));
}

int compAnimals(animal anm1, animal anm2)
{
	return (
		!strcmp(anm1.name, anm2.name)
		&&
		!strcmp(anm1.type, anm2.type)
		&&
		anm1.age == anm2.age
		);
}