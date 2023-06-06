#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //taking height between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while ((height<1)||(height>8));
    
    //loop for number of rows
    for (int i = 0; i<height; i++)
   
    {
        //loops for number of bricks and spaces
        for (int j=0; j<(height-i-1); j++)
        {
            printf(" ");

        }

        for (int j=0; j<i+1; j++)
        {
            printf("#");

        }
        printf("  ");
        
        for (int j=0; j<i+1; j++)
        {
            printf("#");

        }
        printf("\n");
        
    }
}