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

    int largest = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    if (second == INT_MIN) printf("No second largest (all equal)\n");
    else printf("Second largest = %d\n", second);

    return 0;
}