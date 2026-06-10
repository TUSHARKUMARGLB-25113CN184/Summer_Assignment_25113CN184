/*Write a program to Find duplicates in array*/
#include <stdio.h>
int main() {
    int arr[100], n, i, j;
    int foundDuplicate = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Duplicate elements in the array:\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d\n", arr[i]);
                foundDuplicate = 1;
                break; 
            }
        }
    }

    if (!foundDuplicate) {
        printf("No duplicate elements found in the array.\n");
    }

    return 0;
}