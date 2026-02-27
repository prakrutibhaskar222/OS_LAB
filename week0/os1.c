#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least 2 elements\n");
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int smallest = INT_MAX, second = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] < smallest) {
            second = smallest;
            smallest = a[i];
        } else if (a[i] < second && a[i] != smallest) {
            second = a[i];
        }
    }

    if (second == INT_MAX) printf("No second smallest (all equal)\n");
    else printf("Second smallest = %d\n", second);

    return 0;
}