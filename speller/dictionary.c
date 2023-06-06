// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

//words in dictionary
int words_in_dict = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashindex = hash(word);
    node *n = table[hashindex];
    while (n != NULL)
    {
        // compare word
        if (strcasecmp(n->word, word) == 0){return true;}
        // move to next word if not matching
        n = n->next;
    }
    return false;


}

// Hashes word to a number
//djb2 found on http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    // convert word to lower to ignore capitilisation while hashing
    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL){return false;}

    char word[LENGTH+1];

    //while loop that breaks on reaching EOF
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        //check if node created
        if (n == NULL){return false;}

        // copy the word into the node, obtain hash
        strcpy(n->word, word);
        int hashindex = hash(word);

        // insert the node
        n->next = table[hashindex];
        table[hashindex] = n;

        //increment the number of words loaded to dictionary
        words_in_dict++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words_in_dict;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *pos = head;
        node *temp = head;

        while(pos!=NULL){
            pos = pos->next;
            free(temp);
            temp = pos;
        }
    }
    return true;
}