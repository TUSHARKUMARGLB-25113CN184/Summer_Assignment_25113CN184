/*Write a program to Create ATM simulation*/
#include <stdio.h>

int main() {
    double balance = 5000.00; 
    int choice;
    double amount;

    printf("========================================\n");
    printf("        WELCOME TO THE ATM SYSTEM       \n");
    printf("========================================\n");
    do {
        printf("\n--- ATM Main Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid choice! Please enter a number between 1 and 4.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                printf("\n Your current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf(" Invalid amount! Please enter a positive number.\n");
                    while (getchar() != '\n'); 
                } else {
                    balance += amount; 
                    printf(" Success! $%.2f deposited. New balance: $%.2f\n", amount, balance);
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount! Please enter a positive number.\n");
                    while (getchar() != '\n'); 
                } else if (amount > balance) {
                    printf(" Transaction Declined! Insufficient balance.\n");
                    printf("Your current balance is only: $%.2f\n", balance);
                } else {
                    balance -= amount; 
                    printf(" Success! Please collect your cash.\n");
                    printf("Remaining balance: $%.2f\n", balance);
                }
                break;

            case 4:
                printf("\n========================================\n");
                printf("  Thank you for using our ATM. Goodbye! \n");
                printf("========================================\n");
                break;

            default:
                printf("Invalid option! Please choose a number between 1 and 4.\n");
        }

    } while (choice != 4); 

    return 0;
}