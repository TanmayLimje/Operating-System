#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_frame 3

bool hitList (int page, int frames[], int no_frame)
{
    for (int i = 0; i < no_frame; i++)
    {
        if(frames[i] == page)
        {
            return true;
        }
    }
    
    return false;
}

void fcfs (int pages[], int no_page)
{
    int frame[max_frame] = {-1, -1, -1};
    int pageFault = 0;
    
    for (int i = 0; i < no_page; i++)
    {
        int currentPage = pages[i];
    
        if (!hitList (currentPage, frame, max_frame))
        {
            int victimIndex = i % max_frame;
            frame[victimIndex] = currentPage;
            pageFault++;
        }
        
        printf("Page %d -> frame: [", currentPage);
        
        for (int j = 0; j < max_frame; j++)
        {
            printf("%d", frame[j]);
            
            if (j < max_frame - 1)
            {
                printf(", ");
            }
        }
        
        printf("]\n");
        
    }
    
    printf("Total Page Faults (FCFS): %d\n", pageFault);
    
}

int main() {
    int pages[] = { 1,3,0,3,5,6,3 }; 
    int numPages = sizeof(pages) / sizeof(pages[0]);

    printf("Page References: ");
    for (int i = 0; i < numPages; i++) {
        printf("%d", pages[i]);
        if (i < numPages - 1) {
            printf(", ");
        }
    }
    printf("\n\n");

    printf("Frame Size: %d\n", max_frame);
    printf("------------- FCFS -------------\n");
    fcfs(pages, numPages);
    printf("\n");

    return 0;
}








