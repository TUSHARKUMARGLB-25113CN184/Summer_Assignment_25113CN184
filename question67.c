/*Write a program to Intersection of arrays.*/
#include <stdio.h>


int isPresent(int arr[], int size, int element) {
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

    int minSize = (size1 < size2) ? size1 : size2;
    int intersectArr[minSize];
    int k = 0; 

    
    for (int i = 0; i < size1; i++) {
        if (isPresent(arr2, size2, arr1[i]) && !isPresent(intersectArr, k, arr1[i])) {
            intersectArr[k] = arr1[i];
            k++;
        }
    }
    printf("Intersection of the two arrays: \n");
    if (k == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < k; i++) {
            printf("%d ", intersectArr[i]);
        }
    }
    printf("\n");

    return 0;
}