/*Write a program to Find string length 
without strlen()*/

#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    scanf("%c", str);
    while (str[length] != '\0') {
        length++; 
    }
    printf("Length of the string is: %d\n", length);

    return 0;
}