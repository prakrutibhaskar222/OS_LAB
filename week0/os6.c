#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("Invalid size\n");
        return 0;
    }

    int a[1000];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[n - 1] = 0; // optional cleanup
    n--;

    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
