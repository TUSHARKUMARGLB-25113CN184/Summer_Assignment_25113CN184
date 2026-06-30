/*Write a program to Create bank account 
system */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    double balance;
} Account;
void createAccount(Account accounts[], int *totalAccounts);
void deposit(Account accounts[], int totalAccounts);
void withdraw(Account accounts[], int totalAccounts);
void checkBalance(const Account accounts[], int totalAccounts);
void displayAllAccounts(const Account accounts[], int totalAccounts);
int findAccountIndex(const Account accounts[], int totalAccounts, int accNum);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;

    printf("--- Welcome to the Bank Account Management System ---\n");

    while (1) {
        printf("\n===================================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 

        switch (choice) {
            case 1:
                createAccount(accounts, &totalAccounts);
                break;
            case 2:
                deposit(accounts, totalAccounts);
                break;
            case 3:
                withdraw(accounts, totalAccounts);
                break;
            case 4:
                checkBalance(accounts, totalAccounts);
                break;
            case 5:
                displayAllAccounts(accounts, totalAccounts);
                break;
            case 6:
                printf("\nThank you for using our banking system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option (1-6).\n");
        }
    }
    return 0;
}
void createAccount(Account accounts[], int *totalAccounts) {
    if (*totalAccounts >= MAX_ACCOUNTS) {
        printf("\nError: Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account newAcc;
    printf("\nEnter a new Account Number (Integer): ");
    scanf("%d", &newAcc.accountNumber);
    getchar(); 
    if (findAccountIndex(accounts, *totalAccounts, newAcc.accountNumber) != -1) {
        printf("Error: An account with number %d already exists!\n", newAcc.accountNumber);
        return;
    }

    printf("Enter Account Holder Name: ");
    fgets(newAcc.name, NAME_LEN, stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = 0; 

    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &newAcc.balance);

    if (newAcc.balance < 0) {
        printf("Error: Initial deposit cannot be negative. Account creation failed.\n");
        return;
    }
    accounts[*totalAccounts] = newAcc;
    (*totalAccounts)++;

    printf("\nSuccess: Account created successfully for %s!\n", newAcc.name);
}
void deposit(Account accounts[], int totalAccounts) {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }

    printf("Enter amount to deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("\nSuccess: $%.2f deposited. New Balance: $%.2f\n", amount, accounts[index].balance);
}
void withdraw(Account accounts[], int totalAccounts) {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }

    printf("Enter amount to withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Error: Insufficient balance! Current Balance: $%.2f\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    printf("\nSuccess: $%.2f withdrawn. New Balance: $%.2f\n", amount, accounts[index].balance);
}
void checkBalance(const Account accounts[], int totalAccounts) {
    int accNum;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }

    printf("\n--- Account Details ---");
    printf("\nAccount Number: %d", accounts[index].accountNumber);
    printf("\nHolder Name:    %s", accounts[index].name);
    printf("\nCurrent Balance: $%.2f\n", accounts[index].balance);
}
void displayAllAccounts(const Account accounts[], int totalAccounts) {
    if (totalAccounts == 0) {
        printf("\nNo accounts registered in the system yet.\n");
        return;
    }

    printf("\n%-15s %-30s %-15s\n", "Account No.", "Account Holder", "Balance");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("%-15d %-30s $%-14.2f\n", 
               accounts[i].accountNumber, 
               accounts[i].name, 
               accounts[i].balance);
    }
}
int findAccountIndex(const Account accounts[], int totalAccounts, int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i; 
        }
    }
    return -1;
}