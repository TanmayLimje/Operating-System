// shortest job first

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int pid, bt, at, wt, tat;
}Process;

void swap(Process *a, Process *b)
{
	Process temp = *a;
	*a = *b;
	*b = temp;
}

void sortByAT(Process processes[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(processes[j].at > processes[j+1].at)
			{
				swap(&processes[j], &processes[j+1]);
			}
		}
	}
}

void SJF(Process processes[], int n)
{
	int currTime = 0;
	int totalWT = 0;
	int totalTAT = 0;

	for (int i = 0; i < n; i++)
	{
		processes[i].wt = currTime - processes[i].at;
	
		if(processes[i].wt < 0)
		{
			currTime = processes[i].at;
			processes[i].wt = 0;
		}
	
		processes[i].tat = processes[i].wt + processes[i].bt;
		currTime += processes[i].bt;
	
		totalWT += processes[i].wt;
		totalTAT += processes[i].tat;
	}

	printf("\nProcesses\tBT\tAT\tWT\tTAT\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d\t\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].bt, processes[i].at, processes[i].wt, processes[i].tat);
	}
	
    printf("\nAvg wt: %.2f\n", (float)totalWT / n);
	printf("Avg tat: %.2f\n", (float)totalTAT / n);
}



int main()
{
	int n;

	printf("Enter no of processes:");
	scanf("%d",&n);

	Process processes[n];

	printf("Enter bt and at for each processes:");

	for(int i = 0; i < n; i++)
	{
		processes[i].pid = i+1;

		printf("\nProcess %d - BT:", i+1);
		scanf("%d", &processes[i].bt);

		printf("Process %d - AT:", i+1);
		scanf("%d", &processes[i].at);

	}

	sortByAT(processes,n);
	SJF(processes,n);

	return 0;
}


// ---------------------------------------------------------------------------------------------
// OUTPUT:
    
// tanmay@tanmay-VirtualBox:~/os$ gcc SJF.c
// tanmay@tanmay-VirtualBox:~/os$ ./a.out

// Enter no of processes:3
// Enter bt and at for each processes:

// Process 1 - BT:22
// Process 1 - AT:1

// Process 2 - BT:44
// Process 2 - AT:2

// Process 3 - BT:55
// Process 3 - AT:1

// Processes	BT	AT	WT	TAT
// 1		    22	1	0	22
// 3		    55	1	22	77
// 2		    44	2	76	120

// Avg wt: 32.67
// Avg tat: 73.00
