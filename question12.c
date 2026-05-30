/*Write a program to Find LCM of two numbers*/
#include <stdio.h>
int main() {
    int num1, num2, lcm;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    lcm = (num1 > num2) ? num1 : num2; 

    while (1) {
        if (lcm % num1 == 0 && lcm % num2 == 0) {
            break;
        }
        lcm++;
    }

    printf("LCM of %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}
