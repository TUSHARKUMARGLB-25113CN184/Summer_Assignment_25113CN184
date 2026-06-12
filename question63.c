/*Write a program to Find pair with given sum*/

#include <stdio.h>

void findPairBruteForce(int arr[], int size, int target) {
    int found = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
                
                return; 
            }
        }
    }

    if (!found) {
        printf("No pair found with the given sum.\n");
    }
}

int main() {
  int arr[100] , n; 
    int target;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the number of position: ");
    scanf("%d",&target);

    findPairBruteForce(arr, n, target);

    return 0;
}