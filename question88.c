/*Write a program to Remove spaces from 
string*/
#include <stdio.h>

void removeSpaces(char str[]) {
    int i = 0; 
    int j = 0; 

    while (str[i] != '\0') {
    
        if (str[i] != ' ' && str[i] != '\t') {
            str[j] = str[i];
            j++;
        }
        i++; 
    }
    
    str[j] = '\0';
}

int main() {
    char str[150];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    int k = 0;
    while (str[k] != '\0') {
        if (str[k] == '\n') {
            str[k] = '\0';
            break;
        }
        k++;
    }

    printf("Original String: \"%s\"\n", str);
    removeSpaces(str);

    printf("After removing space: \"%s\"\n", str);

    return 0;
}