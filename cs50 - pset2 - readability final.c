#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//declaring the letter counting function
int count_letters(string text);
//declaring the word counting function
int count_words(string text);
//declaring the sentence counting function
int count_sentences(string text);

//defining the main function
int main(void)
{
    string text = get_string("Text: ");
    //declaring variable that calculates an average number of letters per 100 words
    float L = ((float)count_letters(text)/(float)count_words(text))*100;
    //declaring variable that calculates an average number of sentences per 100 words
    float S = ((float)count_sentences(text)/(float)count_words(text))*100;
    //declaring variable that calculates Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //stating conditions to print out an appropriate result
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int)round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

//definig the letter counting function
int count_letters(string text)
{
    //declare the vairable for the number of letters and assign its value to 0
    int count = 0;
    //loop that iterates through the text inputed by user and counts letters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //the condition is that we count only letters and not spaces or other characters
        //and we use tolower to make all the letters lowercase
        if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z')
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    return count;
}

//defining the word counting function
int count_words(string text)
{
    //declare the variable for the number of words and assign its value to zero
    int count = 0;
    //loop that iterates through the text inputed by a user and counts words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    return count + 1;
}

//defining the sentence counting function
int count_sentences(string text)
{
    //declare the variable for the number of sentances and assign its value to 0
    int count = 0;
    //loop that iterates through the text inputed by a user and counts sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    return count;
}