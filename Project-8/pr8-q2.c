#include <stdio.h>

int findStringLength(char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}

int main()
{
    char input[100];

    printf("Enter any string: ");
    gets(input);

    int length = findStringLength(input);

    printf("The length of a string is: %d\n", length);

    return 0;
}