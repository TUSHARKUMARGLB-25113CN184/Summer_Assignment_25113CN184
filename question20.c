/*Write a program to Find largest prime factor */
#include <stdio.h>
int main() {
    long long num, maxPrime = -1;

    printf("Enter a number: ");
    scanf("%lld", &num);

    while (num % 2 == 0) {
        maxPrime = 2;
        num /= 2;
    }

    for (long long i = 3; i <= num / 2; i += 2) {
        while (num % i == 0) {
            maxPrime = i;
            num /= i;
        }
    }

    if (num > 2) {
        maxPrime = num;
    }

    if (maxPrime != -1) {
        printf("The largest prime factor is: %lld\n", maxPrime);
    } else {
        printf("No prime factors found.\n");
    }

    return 0;
}