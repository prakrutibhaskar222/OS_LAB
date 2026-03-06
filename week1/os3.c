#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    int firstArrival = p[0].at;
    for (int i = 1; i < n; i++) {
        if (p[i].at < firstArrival) {
            firstArrival = p[i].at;
        }
    }
    printf("\nFirst arrival time: %d\n", firstArrival);

    int completed = 0, currentTime = 0;
    float totalTAT = 0, totalWT = 0;

    while (completed != n) {
        int idx = -1;
        int minRT = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && p[i].rt > 0) {
                if (p[i].rt < minRT) {
                    minRT = p[i].rt;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].rt--;
            currentTime++;


            if (p[idx].rt == 0) {
                p[idx].ct = currentTime;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                totalTAT += p[idx].tat;
                totalWT += p[idx].wt;
                completed++;
            }
        } else {
            currentTime++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f", totalTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);

    return 0;
}
