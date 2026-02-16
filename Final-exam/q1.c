#include <stdio.h>

int main()
{
    int num, i;
    long long factorial = 1;
    
    printf("Enter an integer: ");
    scanf("%d", &num);

    
    if(num < 0)
    {
        printf("Factorial negative number ka exist nahi karta.");
    }
    else
    {
     
        for(i = 1; i <= num; i++)
        {
            factorial = factorial * i;
        }

        printf("Factorial of %d = %lld", num, factorial);
    }

    return 0;
}
