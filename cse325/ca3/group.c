#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Structure for process
struct process {
    int process_id;
    int a_t;
    int b_t;
    int priority;
    int w_t;
    int t_a_t;
    int r_t;
    int t_q;
    int queue;
    int order;
};

// to sort processes based on their priority and arrival time in ascending order
void sorting_by_priority(struct process p[], int n) {
    int i, j;
    struct process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority || (p[i].priority == p[j].priority && p[i].a_t > p[j].a_t)) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// to implement Fixed priority preemptive scheduling for Queue 1
void fixed_priority_preemptive_scheduling(struct process p[], int n) {
    int i, j, time = 0;
    int q1_empty = 1;
    for (i = 0; i < n; i++) {
        p[i].r_t = p[i].b_t;
        if (p[i].queue == 1) {
            q1_empty = 0;
        }
    }
    printf("\nOrder of execution of processes in Queue 1:\n");
    while (1) {
        int flag = 1;
        for (i = 0; i < n; i++) {
            if (p[i].r_t > 0 && p[i].a_t <= time && p[i].queue == 1) {
                flag = 0;
                int lowest_priority = p[i].priority;
                int earliest_a_t = p[i].a_t;
                int earliest_order = p[i].order;
                for (j = 0; j < n; j++) {
                    if (p[j].r_t > 0 && p[j].a_t <= time && p[j].priority == lowest_priority && p[j].queue == 1) {
                        if (p[j].a_t < earliest_a_t || (p[j].a_t == earliest_a_t && p[j].order < earliest_order)) {
                            earliest_a_t = p[j].a_t;
                            earliest_order = p[j].order;
                            i = j;
                        }
                    } else if (p[j].r_t > 0 && p[j].a_t <= time && p[j].priority < lowest_priority && p[j].queue == 1) {
                        lowest_priority = p[j].priority;
                    }
                }
                printf("Process %d starts execution at time %d\n", p[i].process_id, time);
                if (p[i].r_t > 2) { 
                    p[i].r_t -= 2;
                    time += 2;
                    printf("Process %d gets preempted by a higher priority process at time %d\n", p[i].process_id, time);
                } else {
                    time += p[i].r_t;
                    p[i].w_t = time - p[i].b_t - p[i].a_t;
                    p[i].r_t = 0;
                    printf("Process %d finishes execution at time %d\n", p[i].process_id, time);
                }
            }
        }
        if (flag == 1) {
            break;
        }
    }
}

// to implement Round Robin scheduling for Queue 2
void round_robin_scheduling(struct process p[], int n, int x) {
    int i, j, time = 0, remaining = x;
    for (i = 0; i < n; i++) {
        if (p[i].queue == 2) {
            p[i].r_t = p[i].b_t;
        }
    }
    printf("\nOrder of execution of processes in Queue 2:\n");
    while (remaining != 0) {
        int flag = 1;
        for (i = 0; i < n; i++) {
            if (p[i].r_t > 0 && p[i].a_t <= time && p[i].queue == 2) {
                flag = 0;
                printf("Process %d starts execution at time %d\n", p[i].process_id, time);
                if (p[i].r_t > p[i].t_q) {
                    time += p[i].t_q;
                    p[i].r_t -= p[i].t_q;
                    printf("Process %d gets preempted by Round Robin at time %d\n", p[i].process_id, time);
                } else {
                    time += p[i].r_t;
                    p[i].w_t = time - p[i].b_t - p[i].a_t;
                    p[i].r_t = 0;
                    remaining--;
                    printf("Process %d finishes execution at time %d\n", p[i].process_id, time);
                    if(remaining==0) break;
                }
            }
        }
        if (flag == 1) {
            time += 2;
        }
    }
    printf("\n");
}

// to calculate waiting time and turnaround time
void calculate_w_t_t_a_t(struct process p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        p[i].t_a_t = p[i].b_t + p[i].w_t;
    }
}

// to display process details
void display(struct process p[], int n) {
    struct process temp;
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].process_id > p[j].process_id) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tPriority\tQueue Number\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n", p[i].process_id, p[i].a_t, p[i].b_t, p[i].priority, p[i].queue);
    }
}

int main() {
    int n, i, x=0;
    struct process p[MAX];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter details of process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &p[i].process_id);
        printf("Arrival Time: ");
        scanf("%d", &p[i].a_t);
        printf("Burst Time: ");
        scanf("%d", &p[i].b_t);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        printf("Queue Number: ");
        scanf("%d", &p[i].queue);
        if(p[i].queue==2) x++;
        p[i].t_q = 2;
    }

    sorting_by_priority(p, n);
    fixed_priority_preemptive_scheduling(p, n);
    round_robin_scheduling(p, n, x);
    calculate_w_t_t_a_t(p, n);
    display(p, n);

    float avg_w_t = 0, avg_t_a_t = 0, avg_response_time = 0;
    int j;
    struct process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].process_id > p[j].process_id) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nProcess Execution Details:\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tQueue Number\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (i = 0; i < n; i++) {
        p[i].t_a_t = p[i].b_t + p[i].w_t;
        p[i].r_t = 0;
        p[i].w_t += p[i].a_t;
        p[i].t_a_t += p[i].a_t;
        p[i].r_t = 0;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].a_t, p[i].b_t, p[i].priority, p[i].queue, p[i].w_t, p[i].t_a_t, p[i].t_a_t - p[i].b_t);
        avg_w_t += p[i].w_t;
        avg_t_a_t += p[i].t_a_t;
        avg_response_time += p[i].t_a_t - p[i].b_t;
    }
    avg_w_t /= n;
    avg_t_a_t /= n;
    avg_response_time /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_w_t);
    printf("Average Turnaround Time: %.2f\n", avg_t_a_t);
    printf("Average Response Time: %.2f\n", avg_response_time);

    return 0;
}