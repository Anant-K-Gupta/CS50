#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    string text = get_string("Text: ");
    //Char
    int C = 0;
    //Words (starting at 1 as need to add 1 more word which ends scentence as no space after it.)
    int W = 1;
    //End of Scentence
    int E = 0;
    //Avg sentences per 100 words
    float S;
    //Avg letters per 100 words
    float L;
    //Index
    float index;
    
    for (int i=0, n = strlen(text); i<n; i++)
    {
        if(isalpha(text[i]))
        {
            C += 1;
        }
        else if (text[i]==' ')
        {
            W += 1;
        }
        else if (text[i]=='.' || text[i]=='!' || text[i]=='?')
        {
            E += 1;
        }
    }
    
    L = ((float)C/W)*100;
    
    S = ((float)E/W)*100;
    
    index = 0.0588 * L - 0.296 * S - 15.8;
    
    printf("%f\n", index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
    
    
    
    
}