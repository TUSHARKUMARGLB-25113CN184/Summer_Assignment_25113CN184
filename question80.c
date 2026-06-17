/*Write a program to Find column-wise sum*/
#include <stdio.h>

int main() {
    int A[10][10];
    int row, col, colSum;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter element A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n--- Given Matrix ---\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
    for (int j = 0; j < col; j++) { 
        colSum = 0;  
        for (int i = 0; i < row; i++) {
            colSum += A[i][j];
        }
        
        printf("%d\t", colSum);
    }
    printf("<-- Column-wise Sum\n");

    return 0;
}