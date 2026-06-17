/*Write a program to Multiply matrices*/
#include <stdio.h>

int main() {
    int A[10][10], B[10][10], result[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("\nError! Matrix multiplication not possible .\n");
        printf("Matrix A  Columns (%d) Matrix B  Rows (%d) should be equal \n", c1, r2);
        return 1;
    }
    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            printf("Enter element A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of Matrix B:\n");
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("Enter element B[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix (A x B):\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}