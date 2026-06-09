/*Write a program to Find sum and average of 
array*/
#include <stdio.h>
int main() {
    int arr[100], n;
    int i, sum = 0;
    float average;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; 
    }

    average = (float)sum / n;

    printf("Sum of the array is: %d\n", sum);
    printf("Average of the array is: %.2f\n", average);

    return 0;
}