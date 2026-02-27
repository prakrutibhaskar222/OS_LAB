#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i][i];

    printf("Left diagonal sum = %d\n", sum);
    return 0;
}