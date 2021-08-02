/*********************************
* Class: MAGSHIMIM C1			 *
* Week 13           			 *
* Class solution 2  			 *
**********************************/

#include <stdio.h>

#define ROWS 5
#define SEATS_IN_ROW 3

#define CHEAP_TICKET_PRICE 25
#define NORMAL_TICKET_PRICE 35
#define VIP_TICKET_PRICE 50

void printStart();
void printCinema(int cinema[][SEATS_IN_ROW], int rows);
int getOption();
int buyTicket(int mat[][SEATS_IN_ROW], int buyRow, int buyCol);
void ticketMaster(int mat[][SEATS_IN_ROW]);
void popcorn(int cinema[][SEATS_IN_ROW], int rows);
void member(int cinema[][SEATS_IN_ROW]);
void setPrice(int cinema[][SEATS_IN_ROW], int rows);

int main(void)
{
	int cinema[ROWS][SEATS_IN_ROW] = {{CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, VIP_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE}};
	
	int run = 1;
	
	while(run)
	{
		printStart();
		
		switch(getOption())
		{
			case 1:
				printCinema(cinema, ROWS);break;
			case 2:
				ticketMaster(cinema);break;
			case 3:
				popcorn(cinema, ROWS);break;
			case 4:
				member(cinema);break;
			case 5:
				setPrice(cinema, ROWS);break;
			case 6:
				printf("Thank you come again");run = 0;break;
		}
	}
	
	return 0;
}

// print all cinema seats & prices
void printCinema(int mat[][SEATS_IN_ROW], int rows)
{
	int row = 0;
	int col = 0;
	
	for (row=0; row < rows; row++)
	{
		for (col=0; col < SEATS_IN_ROW; col++)
		{
			printf("%d ", mat[row][col]);
		}
		printf("\n");
	}
}

// prints the start text
void printStart()
{
	printf("\nWelcome to MagshiCinema\nSelect an option:\n1 - Print cinema hall\n2 - Buy a ticket\n3 - Print number of taken seats\n4 - Make a seat discount\n5 - Set a new price for all seats\n6 - Exit\n");
}

// gets the selected option to execute (also validates it)
int getOption()
{
	int x = 0;
	
	while(x > 6 || x < 1)
	{
		scanf("%d", &x);
		
		if (x > 6 || x < 1)
			printf("Wrong Choice. Enter again\n");
	}
	
	return x;
}

// gets the seat and if it isn't cought, it marks it as cought (also returns whether or not it was cought)
int buyTicket(int mat[][SEATS_IN_ROW], int buyRow, int buyCol)
{
	if (mat[buyRow][buyCol] < 0)
		return 0;
	
	mat[buyRow][buyCol] = -1;
	
	return 1;
}

// gets the seat from the user and calls buyTicket (also prints to the user the success of the buy)
void ticketMaster(int mat[][SEATS_IN_ROW])
{
	int row = 0;
	int col = 0;
	
	printf("Which row (0-4)? ");
	scanf("%d", &row);
	printf("Which seat (0-2)? ");
	scanf("%d", &col);
	
	if(buyTicket(mat, row, col))
	{
		printf("You got the seat!\n");
	}else{
		printf("Seat taken!\n");
	}
}

// prints the amount of cought seats in the cinema
void popcorn(int cinema[][SEATS_IN_ROW], int rows)
{
	int cought = 0;
	
	for(int row=0; row < rows; row++)
	{
		for(int col=0; col < SEATS_IN_ROW; col++)
		{
			if (cinema[row][col] < 0)
				cought++;
		}
	}
	
	printf("%d taken seats in the cinema\n", cought);
}

// gets from the user the seat and discounts it by 10%
void member(int cinema[][SEATS_IN_ROW])
{
	int row = 0;
	int col = 0;
	
	printf("Which row (0-4)? ");
	scanf("%d", &row);
	printf("Which seat (0-2)? ");
	scanf("%d", &col);
	
	if (cinema[row][col] > 0)
		cinema[row][col] *= 0.9;
}

// sets the price of all of the free seats to an inputed amount
void setPrice(int cinema[][SEATS_IN_ROW], int rows)
{
	int price = 0;
	printf("Enter new price: ");
	scanf("%d", &price);
	
	for(int row=0; row < rows; row++)
	{
		for(int col=0; col < SEATS_IN_ROW; col++)
		{
			if (cinema[row][col] > 0)
				cinema[row][col] = price;
		}
	}
}