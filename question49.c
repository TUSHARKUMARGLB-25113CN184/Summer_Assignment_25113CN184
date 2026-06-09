/*Write a program to Input and display array*/
#include <stdio.h>

int main() {
    int arr[100],n;
    int i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements of the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}