#include <cs50.h>
#include <stdio.h>

int (main)void
{
    long long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num<0);
    
    if valid(num)
    {
        printcomp(num)
        
    }
    else
    {
        printf("INVALID\n");
    }
}

bool valid(long long num)
{
    int length = numlen(num);
    if (len == 13 or len == 15 or len == 16) and (checksum(num));
    {
       return true;
    }
    else
    {
        return false;
    }
}

int numlen(long long num)

{
    int len;
    for (int len = 0, num !=0, num/=num, len++);
    return len;
}

bool checksum(long long num)
{
    int sum=0;
    for (int i=0, num!=0, num/=10, i++)
    {
        if i%2=0
        {
            sum += num%10;
        }
        else
        {
            int digit = (num%10)*2
            sum+= num%10 + num/10
        }
    }
    if sum%10==0
    {
        return true
        
    }
    else
    {
        return false
    }
    
    
}



string printcomp(long long num)
{
    if numlen==13
}