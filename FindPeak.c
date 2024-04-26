# include <stdio.h>

int main()
{
    int n;
    printf("Enter the length of array: ");
    scanf("%d", &n);
    int arr[n];

    for (int i=0; i<n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int lb = 0;
    int ub = n-1;
    while(lb < ub)
    {
        int mid = (lb + ub)/2;
        if(arr[mid] < arr[mid+1])
            lb = mid+1;
        else if(arr[mid] > arr[mid+1])
            ub = mid;
    }
    printf("Value of p is: %d \n", arr[lb]);
}