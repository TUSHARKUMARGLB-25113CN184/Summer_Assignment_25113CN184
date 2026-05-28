/*Write a program to Calculate sum of first N 
natural numbers*/
#include <stdio.h>

int main() {
    int N;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        sum = sum + i;
    }
    printf("The sum is: %d\n", sum);

    return 0;
}