#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

enum diffculty
{
	easy=1,
	moderate,
	hard,
	crazy
};

void printStart(); // prints all the text & rules of the start
int getDigit(int fullNum, int index); // get the [index] digit of [fullNum]
int checkForRangeValidation(int n); // check if password is in the valid range
int checkForRepeatation(int n1, int n2, int n3, int n4); // checks if there are two identical numbers
int createPassword(); // creates a random 4-digit, 1-6 password
void clear_buff(); // clears the buffer
void getDiff(); // get the diffculty, checks it for validation, and sets the diff to it
void setGuesses(); // Sub func to getDiff, sets the number of guesses by the difficulty
int getGuess(); // Get the players quess
int guessGiveFeedback(int g); // Gets the guess, gives feedback, and continue/stop gameLoop
void gameLoop(); // loop the func getGuess and give feedback until right or loses
void lose(); // Print lose message and end/reset the game
void win(); // Print win message and end/reset the game
int playAgain(); // Asks the player if he wants to play again, if so - redo all from create password. else - finish
void printTrophy(); // print ascii representation of a trophy


enum diffculty diff = easy;
int password = 0;
int guesses = 0;
int maxGuesses = 0;

int main()
{
	system("cls");
	do
	{
		password = createPassword();
		printStart();
		getDiff();
		gameLoop();
	}
	while(playAgain());
	
	
	printf("\n\nBye Bye!");
	return 0;
}

int getDigit(int fullNum, int index)
{
	int i = 0;
	for(int j=0, s=10; j<5-index; j++, s*=10) // for sum reason pow didn't always workc correctly so i did it 
		i = s;
		
	return fullNum%i/(i/10);
}

int checkForRangeValidation(int n)
{
	int n1 = getDigit(n, 1);
	int n2 = getDigit(n, 2);
	int n3 = getDigit(n, 3);
	int n4 = getDigit(n, 4);
	
	if (n1<1||n1>6 || n2<1||n2>6 || n3<1||n3>6 || n4<1||n4>6)
	{
		return 1;
	}
	
	return 0;
}

int checkForRepeatation(int n1, int n2, int n3, int n4)
{
	if (n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4)
	{
		return 1;
	}
	
	return 0;
}

int createPassword()
{
	srand(time(NULL));
	int num = rand() % 5309 + 1234;
	
	int n1 = getDigit(num, 1);
	int n2 = getDigit(num, 2);
	int n3 = getDigit(num, 3);
	int n4 = getDigit(num, 4);
	
	if (checkForRangeValidation(num))
	{
		n1 = n2;
	}
	
	while(checkForRepeatation(n1, n2, n3, n4))
	{	
		num = rand() % 5309 + 1234;
		
		n1 = getDigit(num, 1);
		n2 = getDigit(num, 2);
		n3 = getDigit(num, 3);
		n4 = getDigit(num, 4);
		
		if (n1<1||n1>6 || n2<1||n2>6 || n3<1||n3>6 || n4<1||n4>6)
		{
			n1 = n2;
		}
	}
	
	return num;
}

void printStart()
{
	printf("\nWelcome to \"MAGSHIMIM CODE-BREAKER\"!!!\n\n");
	
	printf("A secret password was chosen to protect the credit card of Pancratius,\nthe descendant of Antiochus.\nYour mission is to stop Pancratius by revealing his secret password.\n\n");
	
	printf("The rules are as follows:\n1. In each round you try to guess the secret password (4 distinct digits)\n2. After every guess you'll receive two hints about the password\n   HITS:   The number of digits in your guess which were exactly right.\n   MISSES: The number of digits in your guess which belongs to           the password but were miss-placed.\n3. If you'll fail to guess the password after a certain number of rounds\n   Pancratius will buy all the gifts for Hanukkah!!!\n\n");
	
	printf("Please choose the game level:\n1 - Easy (20 rounds)\n2 - Moderate (15 rounds)\n3 - Hard (10 rounds)\n4 - Crazy (random number of rounds 5-25)\n");
}

void clear_buff()
{
	char c = ' ';
	while ((c = getchar()) != '\n' && c != EOF);
}

void getDiff()
{
	int d = 0;
	do
	{
		printf("Make a choice: ");
		scanf("%d", &d);
		clear_buff();
	}
	while(d<1 || d>4);
		
	diff = d;
	
	setGuesses();
}

void setGuesses()
{
	switch(diff)
	{
		case easy:
			guesses = 20;
			break;
		case moderate:
			guesses = 15;
			break;
		case hard:
			guesses = 10;
			break;
		case crazy:
			srand(time(NULL));
			guesses = rand() % 20 + 5;
			break;
		default:
			printf("Invalid Difficulty\n");
	}
	
	maxGuesses = guesses;
}

int getGuess()
{
	int guess = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	
	do
	{
		printf("\nWrite your guess (only 1-6, no ENTER is needed)\n");
		printf("%d guesses left\n", guesses);
		
		n1 = getche()-48;
		n2 = getche()-48;
		n3 = getche()-48;
		n4 = getche()-48;
		
	}
	while(checkForRepeatation(n1, n2, n3, n4));
	
	guess = n1*1000 + n2*100 + n3*10 + n4;
	
	return guess;
}

int guessGiveFeedback(int g)
{	
	if(checkForRangeValidation(g))
	{
		printf("\nOnly 1-6 are allowed, try again!\n");
		
		return 1;
	}
	else
	{
		int hits = 0;
		int misses = 0;
		
		guesses--;
		
		for(int i=1; i<=4; i++) // Get hits & misses count
		{
			if(getDigit(g, i) == getDigit(password, i))
			{
				hits++;
			}
			else
			{
				for(int j=1; j<=4; j++)
				{
					if(getDigit(g, i) == getDigit(password, j))
					{
						misses++;
						break;
					}
				}
			}
		}
		
		if (hits == 4)
		{
			win();
			return 0;
		}
		
		printf("\nYou got    %d HITS    %d MISSES.\n", hits, misses);
		
		if (guesses <= 0)
		{
			lose();
			return 0;
		}
	}
	
	return 1; // 1 - continue loop. 0 - stop
}

void gameLoop()
{
	int g = getGuess();
	int f = guessGiveFeedback(g);
	
	while(f)
	{
		g = getGuess();
		f = guessGiveFeedback(g);
	}
}

void lose()
{
	printf("\nOOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts.\nNothing left for you...\nThe secret password was %d\n", password);
}

void win()
{
	printf("\n	4 HITS YOU WON!!!\n\nIt took you only %d guesses, you are a professional code breaker!\n", maxGuesses - guesses);
	printTrophy();
}

int playAgain()
{
	char a = ' ';
	
	do
	{
		printf("\nWould you like to play again? (y/n): ");
		a = getche();
	}
	while(a != 'y' && a != 'n');
	
	if(a == 'y')
	{
		return 1;
	}
	
	return 0;
}

void printTrophy()
{
	void p(const char *format) // A private function to print text with \n at the end for convince reasons
	{
		printf(format);
		printf("\n");
	}
	
	p("     888888888888888888888888888888     ");
	p("      8888888888888888888888888888      ");
	p("8888888888888888888888888888888888888888");
	p("8     8888888888888888888888888888     8");
	p("8     8888888888888888888888888888     8");
	p("8     8888888888888888888888888888     8");
	p(" 8     88888888888888888888888888     8");
	p("  8    88888888888888888888888888    8");
	p("   8   88888888888888888888888888   8 ");
	p("    8   888888888888888888888888   8");
	p("     8  888888888888888888888888  8");
	p("      88 8888888888888888888888 88");
	p("        888888888888888888888888");
	p("           888888888888888888");
	p("            8888888888888888");
	p("              888888888888");
	p("                88888888");
	p("                  8888");
	p("                 888888");
	p("                88888888");
	p("              888888888888");
	p("            8888888888888888");
	p("          88888888888888888888");
}



