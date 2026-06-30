/*Write a program to Create menu-driven array 
operations system*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function Prototypes
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
int searchElement(const int arr[], int size);
void reverseArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;
    printf("Enter initial number of elements in the array (0 to %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size > 0 && size <= MAX_SIZE) {
        printf("Enter %d integers: ", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    } else {
        size = 0;
    }

    printf("\n--- Welcome to the Array Operations System ---\n");

    while (1) {
        printf("\n===================================\n");
        printf("1. Display Array\n");
        printf("2. Insert Element at a Position\n");
        printf("3. Delete Element from a Position\n");
        printf("4. Search for an Element\n");
        printf("5. Reverse the Array\n");
        printf("6. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                insertElement(arr, &size);
                break;
            case 3:
                deleteElement(arr, &size);
                break;
            case 4: {
                int index = searchElement(arr, size);
                if (index != -1) {
                    printf("Element found at index %d (Position %d).\n", index, index + 1);
                } else if (size > 0) {
                    printf("Element not found in the array.\n");
                }
                break;
            }
            case 5:
                reverseArray(arr, size);
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}

void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("\nThe array is currently empty.\n");
        return;
    }
    printf("\nCurrent Array: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\nTotal Elements: %d\n", size);
}
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("\nError: Array capacity reached. Overflow condition!\n");
        return;
    }

    int element, position;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d): ", *size + 1);
    scanf("%d", &position);
    if (position < 1 || position > *size + 1) {
        printf("Error: Invalid position choice.\n");
        return;
    }

    int index = position - 1;
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*size)++;

    printf("Success: Element inserted successfully.\n");
}
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array is already empty. Underflow condition!\n");
        return;
    }

    int position;
    printf("\nEnter the position of the element to delete (1 to %d): ", *size);
    scanf("%d", &position);

    if (position < 1 || position > *size) {
        printf("Error: Invalid position choice.\n");
        return;
    }

    int index = position - 1;
    printf("Removed element: %d\n", arr[index]);
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Success: Element deleted successfully.\n");
}
int searchElement(const int arr[], int size) {
    if (size == 0) {
        printf("\nThe array is empty. Nothing to search.\n");
        return -1;
    }

    int target;
    printf("\nEnter the element value to look for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

void reverseArray(int arr[], int size) {
    if (size <= 1) {
        printf("\nArray reverse operation completed (0 or 1 item needs no changes).\n");
        return;
    }

    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end) {
  
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    printf("\nSuccess: Array has been completely reversed.\n");
}