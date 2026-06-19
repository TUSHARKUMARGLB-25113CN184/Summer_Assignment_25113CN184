/*Write a program to Find first non-repeating 
character*/
#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char str[]) {
    int freq[256] = {0};
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i]; 
        }
    }

    return '\0';
}

int main() {
    char str[150];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char result = findFirstNonRepeating(str);

    if (result != '\0') {
        printf("First non repeating character: '%c'\n", result);
    } else {
        printf("In string there is no non-repating character.\n");
    }

    return 0;
}