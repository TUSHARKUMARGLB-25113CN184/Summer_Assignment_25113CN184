/*Write a program to Convert binary to decimal.*/
#include <stdio.h>
int binaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * (1 << i);
        ++i;
    }

    return decimalNumber;
}
int main() {
    long long binaryNum;

    printf("Enter a binary number: ");
    scanf("%lld", &binaryNum);

    int decimalNum = binaryToDecimal(binaryNum);
    printf("Decimal representation: %d\n", decimalNum);

    return 0;
}