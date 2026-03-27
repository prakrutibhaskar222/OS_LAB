#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    char type[10]; // "system" or "user"
};

struct Queue {
    int front, rear, size;
    struct Process *arr[100];
};

void enqueue(struct Queue *q, struct Process *p) {
    q->arr[++q->rear] = p;
    q->size++;
}

struct Process* dequeue(struct Queue *q) {
    if (q->size == 0) return NULL;
    struct Process* p = q->arr[q->front++];
    q->size--;
    return p;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process plist[n];
    for (int i = 0; i < n; i++) {
        plist[i].id = i + 1;
        printf("Enter arrival time for P%d: ", plist[i].id);
        scanf("%d", &plist[i].arrival_time);
        printf("Enter burst time for P%d: ", plist[i].id);
        scanf("%d", &plist[i].burst_time);
        printf("Enter type (system/user) for P%d: ", plist[i].id);
        scanf("%s", plist[i].type);
        plist[i].remaining_time = plist[i].burst_time;
        plist[i].completion_time = 0;
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (plist[i].arrival_time > plist[j].arrival_time) {
                struct Process temp = plist[i];
                plist[i] = plist[j];
                plist[j] = temp;
            }
        }
    }

    struct Queue systemQ = {0, -1, 0};
    struct Queue userQ = {0, -1, 0};

    int current_time = 0, completed = 0, i = 0;
    struct Process *current_process = NULL;

    while (completed < n) {
        // Step 1: Add newly arrived processes
        while (i < n && plist[i].arrival_time <= current_time) {
            if (strcmp(plist[i].type, "system") == 0)
                enqueue(&systemQ, &plist[i]);
            else
                enqueue(&userQ, &plist[i]);
            i++;
        }

        // Step 2: Preemption check
        if (current_process != NULL) {
            if (strcmp(current_process->type, "user") == 0 && systemQ.size > 0) {
                enqueue(&userQ, current_process);
                current_process = NULL;
            }
        }

        // Step 3: Select next process
        if (current_process == NULL) {
            if (systemQ.size > 0)
                current_process = dequeue(&systemQ);
            else if (userQ.size > 0)
                current_process = dequeue(&userQ);
            else {
                current_time++;
                continue;
            }
        }

        // Step 4: Execute for 1 time unit
        current_process->remaining_time--;
        current_time++;

        // Step 5: Completion check
        if (current_process->remaining_time == 0) {
            current_process->completion_time = current_time;
            printf("Process P%d (%s) completed at time %d\n",
                   current_process->id, current_process->type, current_time);
            completed++;
            current_process = NULL;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tType\n");
    for (int k = 0; k < n; k++) {
        int tat = plist[k].completion_time - plist[k].arrival_time;
        int wt = tat - plist[k].burst_time;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
               plist[k].id, plist[k].arrival_time, plist[k].burst_time,
               plist[k].completion_time, tat, wt, plist[k].type);
    }

    return 0;
}
