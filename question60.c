/*Write a program to Move zeroes to end*/
#include <stdio.h>


void moveZeroesToEnd(int arr[], int n) {
    int count = 0; 

    for (int i = 0; i < n; i++) {
        
        if (arr[i] != 0) {
            
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
            
            count++; 
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] , n; 
    int d;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    moveZeroesToEnd(arr, n);

    printf("Array after moving zeroes to the end:\n");
    printArray(arr, n);

    return 0;
}