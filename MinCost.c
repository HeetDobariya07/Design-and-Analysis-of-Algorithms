# include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of licence required: ");
    scanf("%d", &n);
    int rates[n];
    int sortedrates[n];
    int cost = 0;

    // Taking rates as input
    for (int i=0; i<n; i++)
    {
        printf("Enter rate %d: ", i+1);
        scanf("%d", &rates[i]);
    }

    for (int i=0; i<n; i++)
    {
        sortedrates[i] = rates[i];
    }

    // Sorting rates
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (sortedrates[i] < sortedrates[j])
            {
                int temp = sortedrates[i];
                sortedrates[i] = sortedrates[j];
                sortedrates[j] = temp;
            }
        }
    }

    // Printing the order of rates to be taken for minimum cost.
    printf("Order of rates is (rate no., rate): ");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (sortedrates[i] == rates[j])
                printf("(%d,%d) ", j+1, sortedrates[i]);
        }
    }
    printf("\n");

    // Printing the cost required for n licences.
    for (int i=0; i<n; i++)
    {
        cost += sortedrates[i]*100*(i+1);
    }
    printf("The cost to buy licence is: %d \n", cost);
}