/*Write a program to Check anagram strings*/
#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int n = strlen(str);
    int i, j;
    char temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int checkAnagramSorting(char str1[], char str2[]) {
    if (strlen(str1) != strlen(str2)) {
        return 0; 
    }
    sortString(str1);
    sortString(str2);
    if (strcmp(str1, str2) == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (checkAnagramSorting(str1, str2)) {
        printf("Both strings are Anagram \n");
    } else {
        printf("Both strings are not Anagram.\n");
    }

    return 0;
}