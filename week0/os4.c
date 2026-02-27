#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int count = 0;

    for (int i = 0; i < n; i++) {
        int alreadyCounted = 0;
        for (int k = 0; k < i; k++) {
            if (a[i] == a[k]) {  // value appeared before
                alreadyCounted = 1;
                break;
            }
        }
        if (alreadyCounted) continue;

        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) freq++;
        }
        if (freq > 1) count++;
    }

    printf("Total number of duplicate elements = %d\n", count);
    return 0;
}