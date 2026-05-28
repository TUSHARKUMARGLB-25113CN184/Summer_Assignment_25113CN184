/*Write a program to Find factorial of a number*/
#include <stdio.h>

int main() {
    int num, i;
    int factorial = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    } else {
        for (i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %d\n", num, factorial);
    }

    return 0;
}