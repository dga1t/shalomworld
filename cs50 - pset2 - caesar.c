// last complete working version

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //checking if there are only two command-line arguments
    if (argc == 2)
    {
        //first loop checks if there are no letters in the key
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else
            {
                continue;
            }
        }
        //second loop that shifts the characters from plaintext to ciphertext
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                int key = atoi(argv[1]);
                //prompt a user for text to encrypt
                string plaintext = get_string("plaintext: ");

                printf("ciphertext: ");

                //iterating through text inputed by a user
                for (i = 0, n = strlen(plaintext); i < n; i++)
                {
                    if (isalpha(plaintext[i]))
                    {
                        if (isupper(plaintext[i]))
                        {
                            printf("%c", ((toupper(plaintext[i]) - 'A') + key) % 26 + 'A');
                        }
                        else
                        {
                            printf("%c", ((plaintext[i] - 'a') + key) % 26 + 'a');
                        }
                    }
                    else
                    {
                        printf("%c", plaintext[i]);
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// first working version (not complete)

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] >= '0' && argv[1][i] <= '9')
            {
                //prompt a user for text that he wants to encrypts
                string plaintext = get_string("plaintext: ");
                printf("ciphertext: ");

                //iterating through text inputed by a user
                for (i = 0, n = strlen(plaintext); i < n; i++)
                {
                    if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
                    {
                        printf("%c", (char)plaintext[i] + 1);
                    }
                    else
                    {
                        continue;
                    }
                }
            printf("\n");
            }
            else
            {
                printf("Usage: ./caesar key\n");
                break;
            }
        }
    }
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//if (char c == isalpha(plaintext[i])) ???


// first complete yet not working version

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string ciphertext;

    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] >= '0' && argv[1][i] <= '9')
            {
                //prompt a user for text that he wants to encrypt
                string plaintext = get_string("plaintext: ");

                printf("ciphertext: ");

                //iterating through text inputed by a user
                for (i = 0, n = strlen(plaintext); i < n; i++)
                {
                    if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
                    {
                        printf("%c", (char)plaintext[i] + ((int)argv[1] % 25));
                    }
                    if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                    {
                        printf("%c", (char)plaintext[i] + ((int)argv[1] % 25));
                    }
                    else
                    {
                        printf("%c", (char)plaintext[i]);
                    }
                }
            printf("\n");
            }
            else
            {
                printf("Usage: ./caesar key\n");
                break;
            }
        }
    }
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//if (char c == isalpha(plaintext[i])) ???

// second with minor differences yet not working

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string ciphertext;

    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] >= '0' && argv[1][i] <= '9')
            {
                //prompt a user for text that he wants to encrypt
                string plaintext = get_string("plaintext: ");

                printf("ciphertext: ");

                //iterating through text inputed by a user
                for (i = 0, n = strlen(plaintext); i < n; i++)
                {
                    if (islower(plaintext[i]))
                    {
                        printf("%c", (char)plaintext[i] + (atoi(argv[1]) % 25));
                    }
                    if (isupper(plaintext[i]))
                    {
                        printf("%c", (char)plaintext[i] + (atoi(argv[1]) % 25));
                    }
                    else
                    {
                        printf("%c", (char)plaintext[i]);
                    }
                }
            printf("\n");
            }
            else
            {
                printf("Usage: ./caesar key\n");
                break;
            }
        }
    }
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//if (char c == isalpha(plaintext[i])) ???


// so close wtf is wrong?!

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            if (isdigit(argv[1][i]))
            {
                int key = atoi(argv[1]);
                //prompt a user for text that he wants to encrypt
                string plaintext = get_string("plaintext: ");

                printf("ciphertext: ");

                //iterating through text inputed by a user
                for (i = 0, n = strlen(plaintext); i < n; i++)
                {
                    if (isalpha(plaintext[i]))
                    {
                        if (isupper(plaintext[i]))
                        {
                            printf("%c", ((toupper(plaintext[i]) - 'A') + key) % 26 + 'A');
                        }
                        else
                        {
                            printf("%c", ((plaintext[i] - 'a') + key) % 26 + 'a');
                        }
                    }
                    else
                    {
                        printf("%c", plaintext[i]);
                    }
                }
            printf("\n");
            return 0;
            }
        }
    }
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//if (char c == isalpha(plaintext[i])) ???