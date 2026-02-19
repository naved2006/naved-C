#include <stdio.h>

void findCubes(int *arr, int rows, int cols)
{
    printf("Cubes of all elements:\n");
    for (int i = 0; i < rows * cols; i++)
    {
        printf("%d ", (*(arr + i)) * (*(arr + i)) * (*(arr + i)));
    }
}

int main()
{
    int n;
    printf("Enter array's size: ");
    scanf("%d", &n);

    int a[n][n];
    printf("\nEnter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");
    findCubes((int *)a, n, n);

    return 0;
}