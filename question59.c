/*Write a program to Rotate array right*/


#include <stdio.h>


void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


void rotateRight(int arr[], int n, int d) {
    
    d= d%n; 
    
    
    if (d == 0) return;

    
    reverse(arr, 0, n - 1);

    
    reverse(arr, 0, d - 1);

    
    reverse(arr, d, n - 1);
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
    printf("enter the number of position: ");
    scanf("%d",&d);


    printf("Original array: \n");
    printArray(arr, n);

    rotateRight(arr, n, d);

    printf("Array after rotating right by %d steps: \n", d);
    printArray(arr, n);

    return 0;
}