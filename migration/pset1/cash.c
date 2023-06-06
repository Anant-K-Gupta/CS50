#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars<0);
    
    int coins=0;
    
    int cents = round(dollars*100);
    
    
    coins += cents/25;
    cents -= 25*(cents/25);
    
    coins += cents/10;
    cents -= 10*(cents/10);

    coins += cents/5;
    cents -= 5*(cents/5);
    
    coins += cents/1;
    cents -= 1*(cents/1);
    
    printf("%i\n", coins);
    
}
