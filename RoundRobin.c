// round robin
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, quat_time;
	float avg_wt = 0, avg_tat = 0;
	int sq = 0;
	int bt[10], rem_bt[10], wt[10], tat[10];
	
	printf("Enter no of processes: ");
	scanf("%d", &num);

	printf("\nEnter burst time for all processes :");
	for(int i = 0; i < num; i++)
	{
		scanf("%d", &bt[i]);
		rem_bt[i] = bt[i];
	}

	printf("Enter time quantum:");
	scanf("%d", &quat_time);

	while(1)
	{
		int flag = 0;
	
		for(int i = 0; i < num; i++)
		{
			if(rem_bt[i] > 0)
			{
				flag = 1;
				
				if(rem_bt[i] > quat_time)
				{
					rem_bt[i] -= quat_time;
					sq += quat_time;
				}
				else
				{
					sq += rem_bt[i];
					tat[i] = sq;
					rem_bt[i] = 0;
				}
			}
		}

		if(flag == 0)
		{
			break;
		}
	
		printf("\nProcess\tBT\tTAT\tWT \n");
		for(int i = 0; i < num; i++)
		{
			wt[i] = tat[i] - bt[i];
			avg_tat += tat[i];
			avg_wt += wt[i];
			
			printf("%d\t%d\t%d\t%d\n", i+1, bt[i], tat[i], wt[i]);
		}
		
		avg_wt /= num;
		avg_tat /= num;

    printf("\nAvg wt:%f" ,avg_wt);
		printf("\nAvg tat:%f ", avg_tat);

	}
	
	return 0;
	
}

----------------------------------------------------------------------------------------------------------------------------
  output:

tanmay@tanmay-VirtualBox:~/os$ gcc RoundRobin.c 
tanmay@tanmay-VirtualBox:~/os$ ./a.out
Enter no of processes: 3

Enter burst time for all processes :1 4 5
Enter time quantum:2

Process	BT	TAT	WT 
1	 1	 1	 0
2	 4	 0	 -4
3	 5	 0	 -5

Avg wt:-3.000000
Avg tat:0.333333 

Process	BT	TAT	WT 
1      	 1	 1	0
2    	 4	 7	3
3    	 5	 0  	-5

Avg wt:-1.666667
Avg tat:2.777778 

Process	BT	TAT	WT 
1	 1	 1	 0
2	 4	 7	 3
3	 5	 10   	 5

Avg wt:2.111111
Avg tat:6.925926
