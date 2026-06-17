/*Write a program to Find row-wise sum*/
#include <stdio.h>

int main() {
    int A[10][10];
    int row, col, rowSum;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter element A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n--- Matrix and Row-wise Sum ---\n");
    for (int i = 0; i < row; i++) {
        rowSum = 0; 
        for (int j = 0; j < col; j++) {
            printf("%d\t", A[i][j]); 
            rowSum += A[i][j];   
        }
       
        printf("| Sum of Row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}