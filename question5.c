/*Write a program to Find sum of digits of a 
number*/
#include <stdio.h>
int main(){
    int num, originalNum, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    while (num != 0) {
        sum += num % 10; 
        num = num / 10; 
    }

    printf("The sum of digits in %d is: %d\n", originalNum, sum);

    return 0;
}