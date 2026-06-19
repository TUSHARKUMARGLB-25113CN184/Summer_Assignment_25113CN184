/*Write a program to Find first repeating 
character*/
#include <stdio.h>
#include <string.h>

char findFirstRepeating(char str[]) {
    int freq[256] = {0};
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            continue;
        }
        if (freq[(unsigned char)str[i]] > 0) {
            return str[i]; 
        }
        freq[(unsigned char)str[i]]++;
    }

    return '\0'; 
}

int main() {
    char str[150];

    printf("Enter one string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("first repeating character is: '%c'\n", result);
    } else {
        printf("In string there is no repeating character.\n");
    }

    return 0;
}