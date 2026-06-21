/*Write a program to Remove duplicate 
characters*/
#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int len = strlen(str);
    if (len == 0) {
        return;
    }
    int visited[256] = {0};
    int index = 0; 
    for (int i = 0; i < len; i++) {
        char current_char = str[i];
        if (visited[(unsigned char)current_char] == 0) {
            visited[(unsigned char)current_char] = 1;
            str[index] = str[i];
            index++;
        }
    }
    str[index] = '\0';
}

int main() {
    char str[100];
    printf(" Enter string: ");
    scanf("%s",str);

    printf("Original String: %s\n", str);
    
    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);

    return 0;
}