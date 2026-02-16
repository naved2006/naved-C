#include <stdio.h>
#include <string.h>


void countVowels(char str[])
{
    int a=0, e=0, i=0, o=0, u=0;
    int j;

    for(j = 0; str[j] != '\0'; j++)
    {
        if(str[j] == 'a' || str[j] == 'A')
            a++;
        else if(str[j] == 'e' || str[j] == 'E')
            e++;
        else if(str[j] == 'i' || str[j] == 'I')
            i++;
        else if(str[j] == 'o' || str[j] == 'O')
            o++;
        else if(str[j] == 'u' || str[j] == 'U')
            u++;
    }

    printf("\nCount of vowels:\n");
    printf("A or a = %d\n", a);
    printf("E or e = %d\n", e);
    printf("I or i = %d\n", i);
    printf("O or o = %d\n", o);
    printf("U or u = %d\n", u);
}

int main()
{
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    countVowels(sentence);

    return 0;
}