/*Write a program to Check symmetric matrix*/
#include <stdio.h>

int main() {
    int A[10][10];
    int row, col, isSymmetric = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);

    if (row != col) {
        printf("\nIt is not symmetric because it is not square matrix\n");
        return 0;
    }

    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter element A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (A[i][j] != A[j][i]) {
                isSymmetric = 0; 
                break;           
            }
        }
        if (isSymmetric == 0) {
            break; 
        }
    }
    printf("\nGiven Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric == 1) {
        printf("\nResult: It is symmetric matrix\n");
    } else {
        printf("\nResult: It is not a symmetric matrix\n");
    }

    return 0;
}