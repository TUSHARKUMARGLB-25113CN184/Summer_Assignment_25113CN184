/*Write a program to Find common elements*/
#include <stdio.h>

// Function to check if an element already exists in an array
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
     int arr1[100],arr2[100],size1,size2;
    printf("enter the size of array 1: ");
    scanf("%d",&size1);
    printf("enter an array: ");
    for(int i=0;i<size1;i++){
        scanf("%d",&arr1[i]);
    }
     printf("enter the size of array 2: ");
    scanf("%d",&size2);
    printf("enter an array: ");
    for(int i=0;i<size2;i++){
        scanf("%d",&arr2[i]);
    }

   
    int commonArr[size1]; 
    int k = 0; 
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                if (!isDuplicate(commonArr, k, arr1[i])) {
                    commonArr[k] = arr1[i];
                    k++;
                }
                break; 
            }
        }
    }
    printf("Common elements are: ");
    if (k == 0) {
        printf("None");
    } else {
        for (int i = 0; i < k; i++) {
            printf("%d ", commonArr[i]);
        }
    }
    printf("\n");

    return 0;
}