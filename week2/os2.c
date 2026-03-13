#include <stdio.h>

int main() {
    int n, i;
    int bt[20], pr[20], at[20], rt[20], wt[20], tat[20], ct[20], p[20];
    int time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1;

        printf("Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Priority for P%d: ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while (completed < n) {
        int idx = -1;
        int min_pr = 9999;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && pr[i] < min_pr) {
                min_pr = pr[i];
                idx = i;
            }
        }

        if (idx != -1) {
            rt[idx]--;
            time++;

            if (rt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                avg_wt += wt[idx];
                avg_tat += tat[idx];

                completed++;
            }
        } else {
            time++;
        }
    }


    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
    }


    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
