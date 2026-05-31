/*Write a program to Find nth Fibonacci term*/
#include <stdio.h>
int main() {    
    int n, first = 0, second = 1, next;

    printf("Enter the term number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("The 0th Fibonacci term is: %d\n", first);
    } else if (n == 1) {
        printf("The 1st Fibonacci term is: %d\n", second);
    } else {
        for (int i = 2; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
        }
        printf("The %dth Fibonacci term is: %d\n", n, next);
    }

    return 0;
}