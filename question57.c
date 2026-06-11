/*Write a program to Reverse array*/
#include <stdio.h>


void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

       
        start++;
        end--;
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; 
    int size; 
    printf("enter the size of array: ");
    scanf("%d",&size);
    printf("the array are: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, size);

    
    reverseArray(arr, size);

    printf("Reversed array: \n");
    printArray(arr, size);

    return 0;
}