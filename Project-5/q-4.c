#include <stdio.h>

int main() {
    int a[10][10];
    int row, col, i, j;
    int rno, cno;
    int sum = 0;

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

    // Row sum
    printf("\nEnter row number: ");
    scanf("%d", &rno);

    printf("Elements of row %d: ", rno);
    sum = 0;
    for (j = 0; j < col; j++) {
        printf("%d ", a[rno][j]);
        sum = sum + a[rno][j];
    }
    printf("\nThe sum of a row %d: %d\n", rno, sum);

    // Column sum
    printf("\nEnter column number: ");
    scanf("%d", &cno);

    printf("Elements of column %d: ", cno);
    sum = 0;
    for (i = 0; i < row; i++) {
        printf("%d ", a[i][cno]);
        sum = sum + a[i][cno];
    }
    printf("\nThe sum of column %d: %d", cno, sum);

    return 0;
}
