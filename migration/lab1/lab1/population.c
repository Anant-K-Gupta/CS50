#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pop;
    do 
    {
        pop = get_int("What is the starting population?: ");
    }
    while (pop < 9);
    
    int end;
    do 
    {
        end = get_int("What is the ending population?: ");
    }
    while (end < pop);
    
    int n = 0;
    
    while (pop<end)
    {
        //calculating increase and decrease in population
        
        int inc = pop / 3;
        int dec = pop / 4;
        pop = pop + inc - dec;
        n++;
        
    }
    printf("Years: %i\n", n);

}
