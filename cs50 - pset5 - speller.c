// working version

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


// size of hashtable
#define SIZE 1000000

// create nodes for linked list
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

// create hashtable
node* hashtable[SIZE] = {NULL};

// create hash function
unsigned int hash(const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;

        // comma case
        else
            n = 27;

        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}

// create global variable to count size
int dictionarySize = 0;

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    // opens dictionary
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    // create an array for word to be stored in
    char word[LENGTH+1];

    // scan through the file, loading each word into the hash table
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        // increment dictionary size
        dictionarySize++;

        // allocate memory for new word
        node* newWord = malloc(sizeof(node));

        // put word in the new node
        strcpy(newWord->word, word);

        // find what index of the array the word should go in
        int index = hash(word);

        // if hashtable is empty at index, insert
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }

        // if hashtable is not empty at index, append
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }
    }

    // close file
    fclose(file);

    // return true if successful
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    // creates a temp variable that stores a lower-cased version of the word
    char temp[LENGTH + 1];
    int len = strlen(word);
    for(int i = 0; i < len; i++)
        temp[i] = tolower(word[i]);
    temp[len] = '\0';

    // find what index of the array the word should be in
    int index = hash(temp);

    // if hashtable is empty at index, return false
    if (hashtable[index] == NULL)
    {
        return false;
    }

    // create cursor to compare to word
    node* cursor = hashtable[index];

    // if hashtable is not empty at index, iterate through words and compare
    while (cursor != NULL)
    {
        if (strcmp(temp, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    // if you don't find the word, return false
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    // if dictionary is loaded, return number of words
    if (dictionarySize > 0)
    {
        return dictionarySize;
    }

    // if dictionary hasn't been loaded, return 0
    else
        return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    // create a variable to go through index
    int index = 0;

    // iterate through entire hashtable array
    while (index < SIZE)
    {
        // if hashtable is empty at index, go to next index
        if (hashtable[index] == NULL)
        {
            index++;
        }

        // if hashtable is not empty, iterate through nodes and start freeing
        else
        {
            while(hashtable[index] != NULL)
            {
                node* cursor = hashtable[index];
                hashtable[index] = cursor->next;
                free(cursor);
            }

            // once hashtable is empty at index, go to next index
            index++;
        }
    }

    // return true if successful
    return true;
}


// not working version

// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 10000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Hash table
node *hashtable[HASHTABLE_SIZE];

// Hashes word to a number
int hash(const char *word)
{
    // TODO
    unsigned hashval;
    for (hashval = 0; *word != '\0'; word++)
    {
        hashval = *word + 31 * hashval;
    }
    return hashval % N;
}

// Number of words loaded from the dictionary
int wordcount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    // adds null terminator to end the string
    word_copy[n] = '\0';
    // initializes index for hashed word
    int h = hash_index(word_copy);
    // sets cursor to point at same location as head
    node *cursor = hashtable[h];
    // Sets cursor to point to same location as head

    // If the word exists, you should be able to find in dictionary data structure.
    // Check for word by asking, which bucket would word be in? hashtable[hash(word)]
    // While cursor does not point to NULL, search dictionary for word.
    while (cursor != NULL)
    {
        // if strcasecmp returns true, then word has been found
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        // else word has not yet been found, advance cursor
        else
        {
            cursor = cursor -> next;
        }
    }
    // cursor has reached end of list and word has not been found in dictionary so it must be misspeled
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    // open a dictionary file
    FILE *file = fopen(dictionary, 'r');
    if (file == NULL)
    {
        printf("Could not open the file.\n");
        return false;
    }
    // scans dictionary word by word (populatin hash tables with nodes containing words found in dictionary)

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // mallocs a node for each new word (creates node pointers)
        node *new_node = malloc(sizeof(node));
        // checks if malloc succeeded, returns false if not
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        // copy the word into node if malloc succeeds
        strcpy(new_node->word, word);

        // initializes & calculates index of word for insertion into hashtable
        int h = hash_index(new_node->word);

        // initializes head to point to hashtable index/bucket
        node *head = hashtable[h];

        // insert node at a hash table at that location
        if (head == NULL)
        {
            hashtable[h] = new_node;
            wordcount++;
        }
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
            wordcount++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *head = NULL;
    node *cursor = head;
    // freeing linked lists
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}
