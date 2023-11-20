// page replacement

#include <stdio.h>
#include <stdlib.h>

#define MAX_F 10

void printFrames(int f[], int capacity)
{
	for(int i = 0; i < capacity; i++)
	{
		if(f[i] == -1)
			printf("- ");
		else
			printf("%d(%d) ", f[i], i+1);
	}

	printf("\n");
}

void fifo(int pages[], int n, int capacity)
{
	int frames[MAX_F];
	int faults = 0;
	int frameIndex = 0;

	printf("\n FIFO: \n");

	for(int i = 0; i < n; i++)
	{
		int found = 0;

		for(int j = 0; j < capacity; j++)
		{
			if(frames[j] == pages[i])
			{
				found = 1;
				break;
			}
		}

		if(!found)
		{
			faults++;

			if(frameIndex < capacity)
			{
				frames[frameIndex++] = pages[i];
			}
			else
			{
				int oldest = 0;
		
				for(int j = 1; j < capacity; j++)
				{
					if(frames[j] < frames[oldest])
					{
						oldest = j;
					}
				}
				frames[oldest] = pages[i];
			}
		}
			printf("\nFrames: \n");
		printFrames(frames, capacity);
	}
	printf("\nTotal page faults: %d\n", faults);
}

void LRU (int pages[], int n, int capacity)
{
	int frames[MAX_F];
	int lru[MAX_F];
	int faults = 0;
	int i,j;
	
	printf("\nLRU:\n");
	
	for(i = 0; i < n; i++)
	{
		int found = 0;
		
		for( j = 0 ; j < capacity; j++)
		{
			if(frames[j] = pages[i])
			{
				found = 1;
				lru[j] = i;
				break;
			}
		}
		
		if(!found)
		{
			faults++;
	
			printf("MISS: page %d \n", pages[i]);
			
			if(i < capacity)
			{
				frames[i] = pages[i];
				lru[i] = i;
			}
			else
			{
				int least = 0;				

				for( j = 0; j < capacity; j++)
				{
					if(lru[j] < lru[least])
					{
						least = j;
					}
				}
				
				frames[least] = pages[i];
				lru[least] = i;

			}
		}
		else
		{
			printf("HIT: page %d \n", pages[i]);
		}
	}

	printf("Total page faults : %d \n", faults);
	
}

void optimal(int pages[], int n, int capacity)
{
	int frames[MAX_F];
	int faluts = 0;
	int i,j,k;	

	printf("\nOptimal:\n");	

	for(i = 0; i < n; i++)
	{
		int found = 0;		

		for(j = 0; j < capacity; j++)
		{
			if(frames[j] == pages[i])
			{
				found = 1;
				break;
			}
		}		

		if(!found)
		{
			faluts++;			

			printf("MISS: page %d \n", pages[i]);			

			if (i < capacity)
			{
				frames[i] = pages[i];
			}
			else
			{
				int index[MAX_F];				

				for(j = 0; j < capacity; j++)
				{
					index[j] = -1;
					
					for( k = i+1; k < n; k++)
					{
						if(frames[j] == pages[i])
						{
							index[j] = k;
							break;
						}
					}
				}				

				int furthest = 0;			

				for (j = 0; j < capacity; j++)
				{
					if(index[j] == -1 || index[j] > index[furthest])
					{
						furthest = j;
					}
				}		

				frames[furthest] = pages[i];
			}	
		}
		else
		{
			printf("HIT: page %d \n",pages[i]);
		}
	}
	printf("Total page faluts: %d \n", faluts);
}



int main()
{
	int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,1,2};
	int n = sizeof(pages) / sizeof(pages[0]);
	int capacity = 3;

	fifo(pages,n,capacity);
	LRU(pages,n,capacity);
	optimal(pages,n,capacity);

	return 0;
}

//-------------------------------------------------------------------
//  FIFO: 

// Frames: 
// 7(1) 0(2) 0(3) 

// Frames: 
// 7(1) 0(2) 0(3) 

// Frames: 
// 7(1) 1(2) 0(3) 

// Frames: 
// 7(1) 1(2) 2(3) 

// Frames: 
// 7(1) 0(2) 2(3) 

// Frames: 
// 7(1) 3(2) 2(3) 

// Frames: 
// 7(1) 3(2) 0(3) 

// Frames: 
// 7(1) 3(2) 4(3) 

// Frames: 
// 7(1) 2(2) 4(3) 

// Frames: 
// 7(1) 3(2) 4(3) 

// Frames: 
// 7(1) 0(2) 4(3) 

// Frames: 
// 7(1) 3(2) 4(3) 

// Frames: 
// 7(1) 1(2) 4(3) 

// Frames: 
// 7(1) 2(2) 4(3) 

// Total page faults: 13

// LRU:
// HIT: page 7 
// MISS: page 0 
// HIT: page 1 
// HIT: page 2 
// MISS: page 0 
// HIT: page 3 
// MISS: page 0 
// HIT: page 4 
// HIT: page 2 
// HIT: page 3 
// MISS: page 0 
// HIT: page 3 
// HIT: page 1 
// HIT: page 2 
// Total page faults : 4 

// Optimal:
// MISS: page 7 
// HIT: page 0 
// MISS: page 1 
// MISS: page 2 
// HIT: page 0 
// MISS: page 3 
// HIT: page 0 
// MISS: page 4 
// MISS: page 2 
// MISS: page 3 
// HIT: page 0 
// HIT: page 3 
// MISS: page 1 
// MISS: page 2 
// Total page faluts: 9
