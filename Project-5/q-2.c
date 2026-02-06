#include <stdio.h>

int main() {
    int a[10][10];
    int row, col, i, j;
    int max;

    printf("Enter the array's row size: ");
    scanf("%d", &row);

    printf("Enter the array's column size: ");
    scanf("%d", &col);

    printf("\nEnter array's elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    max = a[0][0];

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }

    printf("\nThe largest element is: %d", max);

    return 0;
}
