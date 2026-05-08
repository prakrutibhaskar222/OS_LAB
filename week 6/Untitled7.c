#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m], avail[m];

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    int finish[n];
    for (int i = 0; i < n; i++) finish[i] = 0;

    int work[m];
    for (int j = 0; j < m; j++) work[j] = avail[j];

    int changed;
    do {
        changed = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canFinish = 1;
                for (int j = 0; j < m; j++) {
                    if (request[i][j] > work[j]) {
                        canFinish = 0;
                        break;
                    }
                }
                if (canFinish) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    finish[i] = 1;
                    changed = 1;
                }
            }
        }
    } while (changed);

    int deadlock = 0;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock = 1;
            printf("Process P%d is in deadlock.\n", i);
        }
    }
    if (!deadlock) printf("No deadlock detected.\n");

    return 0;
}
