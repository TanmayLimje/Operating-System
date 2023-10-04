#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void bubbleSort(int arr[], int n) 
{  
    int temp;    

    for (int i = 0; i < n - 1; i++) 

    {

        for (int j = 0; j < n - 1; j++) 

        {

            if (arr[j] > arr[j + 1]) 

            {

               

                temp = arr[j + 1];

                arr[j + 1] = arr[j];

                arr[j] = temp;

            }

        }

    }

}



int main() 

{

    int n;



    printf("Enter the number of integers: ");

    scanf("%d", &n);

    

    int arr[n];



    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)

    {

        scanf("%d", &arr[i]);

    }



    int pid = fork();



    if (pid < 0) 

    {

        perror("Fork failed");

        exit(1);

    }



    if (pid == 0) 

    { 

        printf("Child process sorting the integers...\n");

        

        bubbleSort(arr, n);

        

        printf("Child process sorted the integers.\n");

        

    } 

    else 

    { 

        printf("Parent process waiting for the child to finish...\n");

        

        wait(NULL); 

        

        printf("Parent process sorted the integers.\n");

        

        printf("Sorted integers: ");

        for (int i = 0; i < n; i++)

        {

            printf("%d ", arr[i]);

        }

        

        printf("\n");

    }



    return 0;

}

