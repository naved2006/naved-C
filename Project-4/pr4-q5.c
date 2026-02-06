#include<stdio.h>

int main(){
    int n = 5;
    for(int i = 1; i <= n; i++){
        for(int s = 1; s <= n - i; s++)
            printf("  ");
        for(int j = n - i + 1; j <= n; j++)
            printf("%d ", j);
        for(int k = n - 1; k >= n - i + 1; k--)
            printf("%d ", k);
        printf("\n");
    }
    return 0;
}