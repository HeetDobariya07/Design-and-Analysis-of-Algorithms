#include <stdio.h>

void main()
{
	int arr[6] = {5, 4, 10, 1, 6, 2};
	int n = 6;
    int pivot;
	for (int i = 1; i < n; i++) 
	{
		pivot = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > pivot) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = pivot;
	}
    for (int i = 0; i < n; i++)
		printf("%d \n", arr[i]);
}
