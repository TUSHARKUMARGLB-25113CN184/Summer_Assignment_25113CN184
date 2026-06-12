/*Write a program to Find maximum frequency 
element*/
#include <stdio.h>

void findMaxFrequencyElement(int arr[], int n) {
    int maxElement = arr[0];
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        
        
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

       
        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }

    printf("Element with maximum frequency: %d\n", maxElement);
    printf("Frequency: %d times\n", maxCount);
}

int main() {
       int arr[100] , n; 
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    findMaxFrequencyElement(arr, n);

    return 0;
}