/*Write a program to Create salary management 
system*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct SalarySystem {
    int empId;
    char name[50];
    float basicSalary;
    float hra;        // House Rent Allowance
    float da;         // Dearness Allowance
    float pf;         // Provident Fund (Deduction)
    float grossSalary;
    float netSalary;
};
void addSalaryRecord(struct SalarySystem emp[], int *count);
void displaySalarySlips(struct SalarySystem emp[], int count);
void searchSalarySlip(struct SalarySystem emp[], int count);

int main() {
    struct SalarySystem empList[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n==== SALARY MANAGEMENT SYSTEM ====");
        printf("\n=================================");
        printf("\n1. Add Employee Salary Record");
        printf("\n2. Display All Salary Slips");
        printf("\n3. Search Salary Slip by Employee ID");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSalaryRecord(empList, &employeeCount);
                break;
            case 2:
                displaySalarySlips(empList, employeeCount);
                break;
            case 3:
                searchSalarySlip(empList, employeeCount);
                break;
            case 4:
                printf("\nExiting Salary Management System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose between 1 and 4.\n");
        }
    }
    return 0;
}

void addSalaryRecord(struct SalarySystem emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nDatabase limit reached!\n");
        return;
    }

    printf("\n--- Enter Salary Details ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &emp[*count].empId);

    getchar(); 

    printf("Enter Employee Name: ");
    fgets(emp[*count].name, sizeof(emp[*count].name), stdin);
    emp[*count].name[strcspn(emp[*count].name, "\n")] = 0; 

    printf("Enter Basic Salary (INR): ");
    scanf("%f", &emp[*count].basicSalary);
    emp[*count].hra = emp[*count].basicSalary * 0.20; 
    emp[*count].da = emp[*count].basicSalary * 0.50;  
    emp[*count].pf = emp[*count].basicSalary * 0.12; 
    emp[*count].grossSalary = emp[*count].basicSalary + emp[*count].hra + emp[*count].da;
    emp[*count].netSalary = emp[*count].grossSalary - emp[*count].pf;

    (*count)++;
    printf("\nSalary record processed and added successfully!\n");
}

void displaySalarySlips(struct SalarySystem emp[], int count) {
    if (count == 0) {
        printf("\nNo salary records found.\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("%-8s %-18s %-12s %-10s %-10s %-10s %-12s %-12s\n", 
           "ID", "Name", "Basic Pay", "HRA(20%)", "DA(50%)", "PF(12%)", "Gross Pay", "Net Salary");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-8d %-18s %-12.2f %-10.2f %-10.2f %-10.2f %-12.2f %-12.2f\n", 
               emp[i].empId, emp[i].name, emp[i].basicSalary, emp[i].hra, emp[i].da, emp[i].pf, emp[i].grossSalary, emp[i].netSalary);
    }
    printf("------------------------------------------------------------------------------------------------------\n");
}
void searchSalarySlip(struct SalarySystem emp[], int count) {
    if (count == 0) {
        printf("\nNo salary records available.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to generate Payslip: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (emp[i].empId == searchId) {
            printf("\n========================================");
            printf("\n          EMPLOYEE PAYSLIP              ");
            printf("\n========================================");
            printf("\nEmployee ID   : %d", emp[i].empId);
            printf("\nEmployee Name : %s", emp[i].name);
            printf("\n----------------------------------------");
            printf("\n(+) Basic Pay : Rs. %.2f", emp[i].basicSalary);
            printf("\n(+) HRA (20%%) : Rs. %.2f", emp[i].hra);
            printf("\n(+) DA  (50%%) : Rs. %.2f", emp[i].da);
            printf("\n(-) PF  (12%%) : Rs. %.2f", emp[i].pf);
            printf("\n----------------------------------------");
            printf("\nGROSS SALARY  : Rs. %.2f", emp[i].grossSalary);
            printf("\nNET TAKE-HOME : Rs. %.2f", emp[i].netSalary);
            printf("\n========================================\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nRecord not found for Employee ID %d.\n", searchId);
    }
}