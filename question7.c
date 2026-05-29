/*Write a program to Find product of digits. */
#include <stdio.h>
int main() {
    int num, originalNum;
    int product = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    while (num != 0) {
        product *= num % 10; 
        num = num / 10; 
    }

    printf("The product of digits in %d is: %d\n", originalNum, product);

    return 0;
}