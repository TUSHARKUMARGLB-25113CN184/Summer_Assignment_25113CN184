/*Write a program to Merge arrays*/
#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i, j;

    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    
    for (j = 0; j < size2; j++) {
        merged[size1 + j] = arr2[j];
    }
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
    int sizeMerged = size1 + size2;

    
    int merged[sizeMerged];

   
    mergeArrays(arr1, size1, arr2, size2, merged);

    
    printf("Merged Array: \n");
    for (int i = 0; i < sizeMerged; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}