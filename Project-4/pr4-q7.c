#include <stdio.h>

int main() {
    int n = 7;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            if(j == 1 || (i == 1 && j <= 4) || (i == 4 && j <= 4) || (j == 5 && i >= 2 && i <= 3)) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}