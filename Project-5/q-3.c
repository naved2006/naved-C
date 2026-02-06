#include <stdio.h>

int main() {
    int a[10][10], t[10][10];
    int n, i, j;

    printf("Enter the array's row & column size: ");
    scanf("%d", &n);

    printf("\nEnter array's elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("\nThe transpose matrix of an array:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
