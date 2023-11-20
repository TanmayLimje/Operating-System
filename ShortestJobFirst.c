//sjf

#include <stdio.h>

#include <stdlib.h>



typedef struct {

    int process_id;

    int burst_time;

    int arrival_time;

    int waiting_time;

    int turnaround_time;

} Process;



void swap(Process *a, Process *b) {

    Process temp = *a;

    *a = *b;

    *b = temp;

}



void sortProcessesByArrivalTime(Process processes[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (processes[j].arrival_time > processes[j + 1].arrival_time) {

                swap(&processes[j], &processes[j + 1]);

            }

        }

    }

}



void sjfScheduling(Process processes[], int n) {

    int currentTime = 0;

    int totalWaitingTime = 0, totalTurnaroundTime = 0;



    for (int i = 0; i < n; i++) {

        processes[i].waiting_time = currentTime - processes[i].arrival_time;



        if (processes[i].waiting_time < 0) {

            currentTime = processes[i].arrival_time;

            processes[i].waiting_time = 0;

        }



        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        currentTime += processes[i].burst_time;



        totalWaitingTime += processes[i].waiting_time;

        totalTurnaroundTime += processes[i].turnaround_time;

    }



    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time,

               processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);

    }



    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);

    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);

}



int main() {

    int n;



    printf("Enter the number of processes: ");

    scanf("%d", &n);



    Process processes[n];



    printf("Enter burst time and arrival time for each process:\n");

    for (int i = 0; i < n; i++) {

        processes[i].process_id = i + 1;

        printf("Process %d - Burst Time: ", i + 1);

        scanf("%d", &processes[i].burst_time);

        printf("Process %d - Arrival Time: ", i + 1);

        scanf("%d", &processes[i].arrival_time);

    }



    // Sort processes by arrival time

    sortProcessesByArrivalTime(processes, n);



    // Execute SJF Scheduling algorithm

    sjfScheduling(processes, n);



    return 0;

}
