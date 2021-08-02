#include <stdio.h>

#define ILSTOAED 1.0873

int main()
{
  int ils=1;
  printf("Welcome to United Arab Emirates, how many ILS you have?\n");
  scanf("%d",&ils);
  printf("You have %.2f Dirham\n", ILSTOAED*ils);

  return 0;
}
