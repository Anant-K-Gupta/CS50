#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Check is key exists
    if (argc != 2)
    {
        printf("useage: ./substitution key\n");
        return 1;
    }
    
    int nonalpha = 0;
    int repeat = 0;
    
    // checking for non alphabetical characters in key
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            nonalpha = 1;
        }
    }
    
    //checking for repeat characters
    for (int i = 0, n = strlen(argv[1]); i < (n - 1); i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (argv[1][i] == argv[1][i + j + 1])
            {
                printf("Key contains repeat characters\n");
                return 1;
            }
        }
    }
    //Checking key length
    if (strlen(argv[1]) != 26)
    {
        printf("Provide key of 26 charcters\n");
        return 1;
    }
    
    else if (nonalpha == 1)
    {
        printf("Enter a valid key\n");
        return 1;
    }
    
        
    string p = get_string("plaintext: "); 
    
    int n;
    
    printf("ciphertext: ");
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        //UPPERCASE
        if (isalpha(p[i]) && isupper(p[i]))
        {
            n = (int)p[i] - 65;
            printf("%c", toupper(argv[1][n]));
        }
        //lowercase
        else if (isalpha(p[i]) && islower(p[i]))
        {
            n = (int)p[i] - 97;
            printf("%c", tolower(argv[1][n]));
        }
        //OtHeRcAsE
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    
}
