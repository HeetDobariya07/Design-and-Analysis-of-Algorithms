#include <stdio.h>
void main() 
{
    int arr[5]={5,3,4,2,1};
    int n=5;
    int min;
    for (int i = 0; i < (n - 1); i++) 
    {
        min = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i) 
        {
            int swap = arr[i];
            arr[i] = arr[min];
            arr[min] = swap;
        }
    }
    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}