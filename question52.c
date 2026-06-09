/*Write a program to Count even and odd 
elements*/
#include <stdio.h>
int main() {
    int arr[100], n;
    int i, evenCount = 0, oddCount = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    printf("Number of even elements in the array: %d\n", evenCount);
    printf("Number of odd elements in the array: %d\n", oddCount);

    return 0;
}
