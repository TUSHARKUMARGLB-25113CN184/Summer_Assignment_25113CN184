/*Write a program to Bubble sort*/
#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; 
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
     int arr[100] , size; 
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    printf("enter array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    bubbleSort(arr, size);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}