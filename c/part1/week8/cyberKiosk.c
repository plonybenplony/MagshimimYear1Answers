/*********************************
* Class: MAGSHIMIM C1			 *
* Week 7           				 *
* CyberKiosk		 			 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define SMALL_SHAKE_PRICE 6
#define BIG_SHAKE_PRICE 8
#define TLUSH_PENALTY 2

#define SMALL_CHOICE 'S'
#define BIG_CHOICE 'B'
#define FRUIT_SHAKE_CHOICE 'F'
#define MILK_SHAKE_CHOICE 'M'

/*
Bug Report: 
1. can't get option type
2. getting size option is using %d and not %c
3. sizeChoice and typeChoice were in the wrong order when calling printReceipt


*/


void printMenu(void);
void takeOrder(void);
void printReceipt(char type, char size, int amount, int hasTlush);


int main(void)
{
	printMenu();
	takeOrder();
	
	return 0;
}

/*
This functions print the menu.
input: none
output: none
*/
void printMenu(void)
{
	printf("Welcome to CyberKiosk!\n");
	printf("We have delicious fruit shakes and milkshakes (from rice milk)!\n");
	printf("Small shake costs %d NIS\n", SMALL_SHAKE_PRICE);
	printf("Big shake costs %d NIS\n", BIG_SHAKE_PRICE);
	printf("Do you have a tlush? hmmm.....\n\n\n");	
}

/*
Handles Orders and prints receipt.
input: none
output: none
*/
void takeOrder(void)
{
	char typeChoice = ' ';
	char sizeChoice = ' ';
	int howMany = 0;
	int hasTlush = 0;
	
	printf("What is your order?\n");
	printf("%c - fruitShake\n%c - milkShake\n", FRUIT_SHAKE_CHOICE, MILK_SHAKE_CHOICE);
	typeChoice = getchar();
	
	getchar();
	
	printf("Choose size\n%c-big\n%c-small\n", BIG_CHOICE, SMALL_CHOICE);
	sizeChoice = getchar();
	
	getchar();

	printf("how many would you like (1-9)?\n");
	scanf("%d", &howMany);
	
	printf("Do you have a tlush? click 0 for no, any other number for yes.\n");
	scanf("%d", &hasTlush);

	printReceipt(typeChoice, sizeChoice, howMany, hasTlush);
	
	printf("You will have your order in a few minutes. Thank you for ordering from CyberKiosk!\n");
}

/*
Calculates the price and prints order info to screen
input: type, size and amount of shakes ordered, also if buyer has a tlush
output: none
*/
void printReceipt(char type, char size, int amount, int hasTlush)
{
	int shakePrice = 0, totalPrice = 0;
	
	printf("You ordered %d ", amount);
	
	// SIZE
	if(BIG_CHOICE == size)
	{
		shakePrice = BIG_SHAKE_PRICE;
		printf("BIG ");
	}
	else if (SMALL_CHOICE == size)
	{
		shakePrice = SMALL_SHAKE_PRICE;
		printf("SMALL ");
	}
	else
	{
		printf("***Error! Wrong size***");
	}
	
	// TYPE
	if (FRUIT_SHAKE_CHOICE == type)
	{
		printf("fruitshakes.\n");
	}

	else if (MILK_SHAKE_CHOICE == type)
	{
		printf("milkshakes.\n");
	}
	else 
	{
		printf("***Error! Wrong type***");
	}
	
	// If costumer has a tlush
	if(hasTlush)
	{
		shakePrice += TLUSH_PENALTY;
	}
	
	// multiply price by number of shakes.
	totalPrice = shakePrice * amount;
	
	printf("Total price: %d \n", totalPrice);
}