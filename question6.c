/*Write a program to Reverse a number.*/
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

    printf("The reverse of %d is: %d\n", originalNum, reversedNum);

    return 0;
}