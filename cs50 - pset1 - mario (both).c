// mario less

#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)
{
    // prompting user for input
    int i = get_positive_int("Enter a number:");
    // outer loop building height of the pyramid
    for (int j = 1; j <= i; j++)
    {
        // inner loop building each row with spaces 
        for (int k = i - j; k > 0; k--)
        {
            printf(" ");
        }
        // inner loop building each row with hashes
        for (int y = 1; y <= j; y++)
        {
            printf("#");
        }
        printf("\n");
    }       
}

// prompt user for positive integer
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}


//mario more


#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)
{
    // prompting user for input
    int i = get_positive_int("Enter a height of the pyramids: ");
    // outer loop building height of the pyramid
    for (int j = 1; j <= i; j++)
    {
        // inner loop building each row with spaces
        for (int k = i - j; k > 0; k--)
        {
            printf(" ");
        }
        // inner loop building each row with hashes
        for (int y = 1; y <= j; y++)
        {
            printf("#");
        }
        // printing space between two pyramids
        printf("  ");
        // inner loop building rows of second pyramid with hashes
        for (int z = 1; z <= j; z++)
        {
            printf("#");
        }
        printf("\n");
    } 
}
// promtp user for positive integer
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}
