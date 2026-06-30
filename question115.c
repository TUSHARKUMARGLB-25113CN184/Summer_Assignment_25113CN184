/*Write a program to Create menu-driven 
string operations system*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
void getString(char str[]);
int stringLength(const char str[]);
void stringCopy(char dest[], const char src[]);
void stringConcatenate(char dest[], const char src[]);
void stringReverse(char str[]);
int stringCompare(const char str1[], const char str2[]);

int main() {
    char str1[MAX_SIZE] = "";
    char str2[MAX_SIZE] = "";
    int choice;

    printf("--- Welcome to the String Operations System ---\n");
    printf("Enter the primary string to start: ");
    getString(str1);

    while (1) {
        printf("\n===================================\n");
        printf("Current Primary String: \"%s\"\n", str1);
        printf("-----------------------------------\n");
        printf("1. Find Length of String\n");
        printf("2. Copy to a New String\n");
        printf("3. Concatenate (Join) another String\n");
        printf("4. Reverse the String\n");
        printf("5. Compare with another String\n");
        printf("6. Enter a New Primary String\n");
        printf("7. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 

        switch (choice) {
            case 1:
                printf("\nLength of \"%s\" is: %d\n", str1, stringLength(str1));
                break;

            case 2:
                stringCopy(str2, str1);
                printf("\nSuccess: Copied to a new buffer!\n");
                printf("Original String: \"%s\"\n", str1);
                printf("Copied String:   \"%s\"\n", str2);
                break;

            case 3:
                printf("\nEnter string to append: ");
                getString(str2);
                stringConcatenate(str1, str2);
                printf("\nSuccess: Strings joined.\n");
                break;

            case 4:
                stringReverse(str1);
                printf("\nSuccess: String reversed in place.\n");
                break;

            case 5:
                printf("\nEnter secondary string to compare: ");
                getString(str2);
                int result = stringCompare(str1, str2);
                if (result == 0) {
                    printf("\nBoth strings are exactly identical.\n");
                } else if (result > 0) {
                    printf("\nThe primary string is lexicographically larger.\n");
                } else {
                    printf("\nThe secondary string is lexicographically larger.\n");
                }
                break;

            case 6:
                printf("\nEnter new primary string: ");
                getString(str1);
                break;

            case 7:
                printf("\nExiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select an option between 1 and 7.\n");
        }
    }
    return 0;
}
void getString(char str[]) {
    fgets(str, MAX_SIZE, stdin);
    for (int i = 0; i < MAX_SIZE; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}
int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void stringConcatenate(char dest[], const char src[]) {
    int dest_len = stringLength(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0'; 
}
void stringReverse(char str[]) {
    int start = 0;
    int end = stringLength(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int stringCompare(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i]; 
        }
        i++;
    }
    return str1[i] - str2[i]; 
}