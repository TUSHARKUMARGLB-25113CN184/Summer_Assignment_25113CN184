/*Write a program to Create voting eligibility 
system*/
#include <stdio.h>

int main() {
    int age;

    printf("========================================\n");
    printf("       VOTING ELIGIBILITY SYSTEM        \n");
    printf("========================================\n");

    printf("Please enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("\nError: Invalid input! Age must be a number.\n");
        return 1; 
    }
    if (age < 0) {
        printf("\nError: Age cannot be negative. Please enter a valid age.\n");
    } 
    else if (age >= 18) {
        printf("\n========================================\n");
        printf("Status: ELIGIBLE TO VOTE! \n");
        printf("You are old enough to cast your vote.\n");
        printf("========================================\n");
    } 
    else {
        int yearsLeft = 18 - age;
        printf("\n========================================\n");
        printf("Status: NOT ELIGIBLE TO VOTE \n");
        printf("You must be 18 or older to vote.\n");
        printf("Please wait %d more year(s) to become eligible.\n", yearsLeft);
        printf("========================================\n");
    }

    return 0;
}