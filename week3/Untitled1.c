#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time for process %d: ", p[i].id);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time for process %d: ", p[i].id);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].completion_time = 0;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int time = 0, done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= time) {
                done = 0;
                if (p[i].remaining_time > quantum) {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                } else {
                    time += p[i].remaining_time;
                    p[i].completion_time = time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    p[i].remaining_time = 0;
                }
            }
        }
        int all_waiting = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= time) {
                all_waiting = 0;
                break;
            }
        }
        if (all_waiting) time++;
    } while (!done);

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    int total_wait = 0, total_turn = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival_time,
               p[i].burst_time, p[i].completion_time,
               p[i].turnaround_time, p[i].waiting_time);
        total_wait += p[i].waiting_time;
        total_turn += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turn / n);

    return 0;
}
