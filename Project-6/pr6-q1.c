#include <stdio.h>

int main() {
    char str[100];
    int i, length = 0, flag = 1;

    printf("Enter any string: ");
    scanf("%s", str);

    // Find length without using string functions
    while (str[length] != '\0') {
        length++;
    }

    // Check palindrome
    for (i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        printf("The given string is a Palindrome.");
    } else {
        printf("The given string is NOT a Palindrome.");
    }

    return 0;
}
