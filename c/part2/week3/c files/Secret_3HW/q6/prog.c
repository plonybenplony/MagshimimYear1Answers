#include <stdio.h>
#include <string.h>

#define PASSWORD "maGshimim2017"
#define STR_LEN 16
#define FALSE 0
#define TRUE !FALSE

int main(void)
{
    int pass = FALSE;
    char buff[STR_LEN] = { 0 };

    printf("Enter the password: ");
    //(void)scanf("%s", buff);
    fgets(buff, STR_LEN, stdin); // more than one way to fix it. one is just to switch the scanf to fgets

    if (strcmp(buff, PASSWORD))
    {
        printf("Wrong Password \n");
    }
    else
    {
        printf("Correct Password \n");
        pass = TRUE;
    }

    if (pass) // second is just to put the print the access to the files in the if (strcmp(buff, PASSWORD)) scope. but it's worse if we'll want the pass variable to function
    {
        printf("Access given to the secret files \n");
    }

    (void)getchar();
    (void)getchar();
    return 0;
}