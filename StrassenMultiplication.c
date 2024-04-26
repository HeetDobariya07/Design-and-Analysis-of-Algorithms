#include <stdio.h>

// Function to add two matrices
void add(int n, int A[][n], int B[][n], int C[][n]) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int n, int A[][n], int B[][n], int C[][n]) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen algorithm
void strassen(int n, int A[][n], int B[][n], int C[][n]) 
{
    if (n == 1) 
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P[newSize][newSize], Q[newSize][newSize], R[newSize][newSize], S[newSize][newSize], T[newSize][newSize], U[newSize][newSize], V[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Divide matrices A and B into submatrices
    for (int i = 0; i < newSize; i++) 
    {
        for (int j = 0; j < newSize; j++) 
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute P = (A11 + A22) * (B11 + B22)
    add(newSize, A11, A22, temp1);
    add(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, P);

    // Compute Q = (A21 + A22) * B11
    add(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, Q);

    // Compute R = A11 * (B12 - B22)
    subtract(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, R);

    // Compute S = A22 * (B21 - B11)
    subtract(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, S);

    // Compute T = (A11 + A12) * B22
    add(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, T);

    // Compute U = (A21 - A11) * (B11 + B12)
    subtract(newSize, A21, A11, temp1);
    add(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, U);

    // Compute V = (A12 - A22) * (B21 + B22)
    subtract(newSize, A12, A22, temp1);
    add(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, V);

    // Compute C11 = P + S - T + V
    add(newSize, P, S, temp1);
    subtract(newSize, temp1, T, temp2);
    add(newSize, temp2, V, C11);

    // Compute C12 = R + T
    add(newSize, R, T, C12);

    // Compute C21 = Q + S
    add(newSize, Q, S, C21);

    // Compute C22 = P - Q + R + U
    subtract(newSize, P, Q, temp1);
    add(newSize, temp1, R, temp2);
    add(newSize, temp2, U, C22);

    // Combine submatrices to form matrix C
    for (int i = 0; i < newSize; i++) 
    {
        for (int j = 0; j < newSize; j++) 
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int n, int matrix[][n])
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int n;
    printf("Enter the size of square matrices (nxn): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Matrix C (Result of A x B):\n");
    printMatrix(n, C);

    return 0;
}