/*Write a program to Count digits in a number. */

#include <stdio.h>

int main() {
    int num, originalNum;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    do {
        count++;        
        num = num / 10; 
    } while (num != 0);

    printf("The number of digits in %d is: %d\n", originalNum, count);

    return 0;
}