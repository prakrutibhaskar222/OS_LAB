#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    // Row sums
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) rowSum += a[i][j];
        printf("Sum of row %d = %d\n", i + 1, rowSum);
    }

    // Column sums
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) colSum += a[i][j];
        printf("Sum of column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
