/*Write a program to Union of arrays*/

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

    
    int unionArr[size1 + size2];
    int k = 0; 
   
    for (int i = 0; i < size1; i++) {
        unionArr[k] = arr1[i];
        k++;
    }

    for (int j = 0; j < size2; j++) {
        if (!isPresent(unionArr, k, arr2[j])) {
            unionArr[k] = arr2[j];
            k++;
        }
    }

   
    printf("Union of the two arrays: \n");
    for (int i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}