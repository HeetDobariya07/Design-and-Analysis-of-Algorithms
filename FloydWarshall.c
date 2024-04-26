#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
int n;

void fillDistanceMatrix(int A[n][n], int D[n][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (i == j)
                D[i][j] = 0;
            else if (A[i][j] == 0)
                D[i][j] = INF;
            else
                D[i][j] = A[i][j];
        }
    }
}

void FloydWarshall(int A[n][n], int D[n][n])
{
    fillDistanceMatrix(A, D);
    
    for (int k=0; k<n; k++)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (D[i][k] < INF && D[k][j] < INF)
                {
                    if((D[i][k] + D[k][j]) < D[i][j])
                    {
                        D[i][j] = D[i][k] + D[k][j];
                    } 
                }
            }
        }
    }
}

int main()
{
    printf("Enter the size of array (nxn): ");
    scanf("%d", &n);
    int A[n][n], D[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("Enter element A[%d][%d] : ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    FloydWarshall(A, D);
    
    printf("Adjacency Matrix is: \n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (D[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
