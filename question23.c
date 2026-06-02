/*Write a program to Count set bits in a number*/
#include <stdio.h>
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; 
        n >>= 1; 
    }
    return count;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int setBitsCount = countSetBits(num);
    printf("Number of set bits in %d is: %d\n", num, setBitsCount);

    return 0;
}
