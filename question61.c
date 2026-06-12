/*Write a program to Find missing number in 
array*/


#include <stdio.h>


int findMissingNumber(int arr[], int n) {
    
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    
    return expectedSum - actualSum;
}

int main() {
    
   int arr[100] , n; 
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    
    int missingNumber = findMissingNumber(arr, n);
    
    printf("The missing number is: %d\n", missingNumber);
    
    return 0;
}