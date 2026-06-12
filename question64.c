/*Write a program to Remove duplicates from 
array*/
#include <stdio.h>

int removeDuplicatesUnsorted(int arr[], int n) {
    int newSize = 0; 

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;

        
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    return newSize; 
}

int main() {
    int arr[100] , n; 
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int newSize = removeDuplicatesUnsorted(arr, n);

    printf("Array after removing duplicates (Order Preserved): ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}