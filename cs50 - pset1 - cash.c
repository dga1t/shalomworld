// LAST AND FINALLY CORRECT VERSION

#include <cs50.h>
#include <stdio.h>
#include <math.h>

// prompt user for the amount of change 
int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    //make the user repeat the input if until its a positive number
    while (change < 0);

    //creating a variable to count the number of coins
    int coins = 0;
    //roundind the user input and converting it from dollars to cents 
    change = round(change * 100);
    //creating an integer variable to ease counting
    int cents = change;
    //first loop counting the number of quarters
    while (cents >= 25)
    {
        coins ++;
        cents -= 25;
    }
    //second loop counting the number of dimes
    while (cents >= 10)
    {
        coins ++;
        cents -= 10;
    }
    //third loop counting the number of nickels
    while (cents >= 5)
    {
        coins ++;
        cents -= 5;
    }
    //forth loop counting the number of pennies
    while (cents >= 1)
    {
        coins ++;
        cents -= 1;
    }
    printf("%i\n", coins);
}

// 1st version

#include <cs50.h>
#include <stdio.h>
#include <math.h>

// prompt user for the amount of change 
int change_owed(string prompt)
{
    float change;
    do
    {
        change = get_float("%s", prompt);
    }
    while (change < 0);
    return change;
}

int main(void)
{
    //types of coins
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int count_coins = 0;
    
    //prompting a user for the input
    float change = change_owed("Change owed: ");
    //convert dollars to cents
    int cents = round(change * 100);
    //first loop counting the number of quarters
    for (cents = cents - quarters; cents <= quarters; count_coins++)
    {
        //second loop counting the number of dimes
        for (cents = cents - dimes; cents <= dimes; count_coins++)
        {
            //third loop counting the number of nickels
            for (cents = cents - nickels; cents <= nickels; count_coins++)
            {
                //forth loop countinf the number of pennies
                for (cents = cents - pennies; cents == 0; count_coins++)
                {
                    printf("%i\n", count_coins);
                }
            }
        }
    }
}


// 2nd version

#include <cs50.h>
#include <stdio.h>
#include <math.h>

// prompt user for the amount of change 
int change_owed(string prompt)
{
    float change;
    do
    {
        change = get_float("%s", prompt);
    }
    while (change < 0);
    return change;
}

int main(void)
{
    //types of coins
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int count_coins = 0;
    
    //prompting a user for the input
    float change = change_owed("Change owed: ");
    //convert dollars to cents
    int cents = round(change * 100);
    //first loop counting the number of quarters
    while (cents >= quarters)
    {
        cents -= quarters;
        count_coins ++;
    }
    while (cents >= dimes)
    {
        cents -= dimes;
        count_coins ++;
    } 
    while (cents >= nickels)
    {
        cents -= nickels;
        count_coins ++;
    }
    while (cents >= pennies)
    {
        cents -= pennies;
        count_coins ++;
    }
    printf("%i\n", count_coins);
}


// 3rd version

#include <cs50.h>
#include <stdio.h>
#include <math.h>

// prompt user for the amount of change 
int change_owed(string prompt)
{
    float change;
    do
    {
        change = get_float("%s", prompt);
    }
    while (change < 0);
    return change;
}

int main(void)
{
    //types of coins
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int count_coins = 0;
    
    //prompting a user for the input
    float change = change_owed("Change owed: ");
    //convert dollars to cents
    int cents = round(change * 100);
    //first loop counting the number of quarters
    while (cents > 0)
    {
        if (cents >= quarters)
        {
            cents -= quarters;
            count_coins ++;
        }
        else (cents >= dimes)
        {
            cents -= dimes;
            count_coins ++;
        }
        else (cents >= nickels)
        {
            cents -= nickels;
            count_coins ++;
        }
        else (cents >= pennies)
        {   
            cents -= pennies;
            count_coins ++;
        }
    printf("%i\n", count_coins);
}
