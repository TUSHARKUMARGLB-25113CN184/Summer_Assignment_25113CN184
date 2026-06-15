/*Write a program to Find diagonal sum*/
#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &size);

    int matrix[size][size];
    int main_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;

    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter element a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        main_diagonal_sum += matrix[i][i];
        secondary_diagonal_sum += matrix[i][size - 1 - i];
    }
    printf("\nSum of Principal Diagonal: %d", main_diagonal_sum);
    printf("\nSum of Secondary Diagonal: %d\n", secondary_diagonal_sum);

    return 0;
}