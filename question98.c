/*Write a program to Find common characters 
in strings*/
#include <stdio.h>
#include <string.h>

void findCommonCharacters(const char *str1, const char *str2) {
    int count[256] = {0};
    for (int i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]] = 1; 
    }

    printf("Common Characters: ");
    int found = 0;
    for (int i = 0; str2[i] != '\0'; i++) {
        char ch = str2[i];
        if (count[(unsigned char)ch] == 1) {
            printf("%c ", ch);
            count[(unsigned char)ch] = 0;
            found = 1;
        }
    }

    if (!found) {
        printf("no common character.");
    }
    printf("\n");
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

    findCommonCharacters(str1, str2);

    return 0;
}