/*Write a program to Create menu-driven 
calculator*/

#include <stdio.h>
#include <stdlib.h>
void add();
void subtract();
void multiply();
void divide();

int main() {
    int choice;

    printf("--- Welcome to the Menu-Driven Calculator ---\n");

    while (1) {
        printf("\n===================================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                printf("\nExiting calculator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option (1-5).\n");
        }
    }
    return 0;
}

void add() {
    double a, b;
    printf("\nEnter two numbers to add: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2f + %.2f = %.2f\n", a, b, a + b);
}
void subtract() {
    double a, b;
    printf("\nEnter two numbers to subtract (First - Second): ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2f - %.2f = %.2f\n", a, b, a - b);
}
void multiply() {
    double a, b;
    printf("\nEnter two numbers to multiply: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2f * %.2f = %.2f\n", a, b, a * b);
}
void divide() {
    double a, b;
    printf("\nEnter two numbers to divide (Numerator / Denominator): ");
    scanf("%lf %lf", &a, &b);
    if (b == 0.0) {
        printf("Error: Division by zero is mathematically undefined!\n");
    } else {
        printf("Result: %.2f / %.2f = %.2f\n", a, b, a / b);
    }
}