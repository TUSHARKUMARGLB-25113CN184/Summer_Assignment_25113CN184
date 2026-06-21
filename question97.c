/*Write a program to Merge two sorted arrays*/
#include <stdio.h>
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0; 
    int j = 0; 
    int k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arr1[100];
    int n1;

    int arr2[100];
    int n2;
    printf("Enter the number of element: ");
    scanf("%d",&n1);
    printf("enter array: ");
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the number of element: ");
    scanf("%d",&n2);
    printf("enter array: ");
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }

    int arr3[200];

    mergeArrays(arr1, n1, arr2, n2, arr3);

    printf("Merged Sorted Array: ");
    for (int m = 0; m < n1 + n2; m++) {
        printf("%d ", arr3[m]);
    }
    printf("\n");

    return 0;
}