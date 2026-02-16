#include <stdio.h>

void checkLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        printf("%d is a Leap Year.", year);
    }
    else
    {
        printf("%d is not a Leap Year.", year);
    }
}

int main()
{
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    checkLeapYear(year);

    return 0;
}
