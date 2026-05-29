/*Write a program to Check whether a number is 
palindrome*/
#include <stdio.h>
int main() {
    int num, originalNum, reversedNum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    while (num != 0) {
        int digit = num % 10; 
        reversedNum = reversedNum * 10 + digit; 
        num = num / 10; 
    }

    if (originalNum == reversedNum) {
        printf("%d is a palindrome.\n", originalNum);
    } else {
        printf("%d is not a palindrome.\n", originalNum);
    }

    return 0;
}