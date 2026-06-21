/*Write a program to Check string rotation*/
#include <stdio.h>
#include <string.h>

int isRotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return 0;
    }
    if (len1 == 0) {
        return 1;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] == str2[0]) {
            int j;
            for (j = 0; j < len1; j++) {
                if (str1[(i + j) % len1] != str2[j]) {
                    break; 
                }
            }
            if (j == len1) {
                return 1; 
            }
        }
    }

    return 0;
}

int main() {
    char str1[100];
    char str2[100];
    printf("Enter string 1: ");
    scanf("%s",str1);
    printf("Enter string 2: ");
    scanf("%s",&str2);

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    if (isRotation(str1, str2)) {
        printf("Result: Yes, string 2 have rotation.\n");
    } else {
        printf("Result: No string 2 didnot have rotation\n");
    }

    return 0;
}