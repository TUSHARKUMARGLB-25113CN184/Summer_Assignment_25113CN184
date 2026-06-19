/*Write a program to Check palindrome string*/
#include <stdio.h>
#include <string.h>

void checkPalindromePointer(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    int isPalindrome = 1; 
    while (start < end) {
        if (str[start] != str[end]) {
            isPalindrome = 0; 
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        printf("\"%s\"It is Palindrone.\n", str);
    } else {
        printf("\"%s\"It is not Palindrone. \n", str);
    }
}

int main() {
    char str[100];
    printf("Enter String:  ");
    scanf("%s", str);
    
    checkPalindromePointer(str);
    return 0;
}