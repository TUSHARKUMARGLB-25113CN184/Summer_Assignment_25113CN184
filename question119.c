/*Write a program to Create mini employee 
management system*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;
void addEmployee(Employee emp[], int *count);
void displayEmployees(Employee emp[], int count);
void searchEmployee(Employee emp[], int count);
void deleteEmployee(Employee emp[], int *count);

int main() {
    Employee emp[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===================================\n");
        printf("    EMPLOYEE MANAGEMENT SYSTEM     \n");
        printf("===================================\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(emp, &count);
                break;
            case 2:
                displayEmployees(emp, count);
                break;
            case 3:
                searchEmployee(emp, count);
                break;
            case 4:
                deleteEmployee(emp, &count);
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
void addEmployee(Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: Database is full. Cannot add more employees.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[*count].id);
    getchar(); 

    printf("Enter Employee Name: ");
    fgets(emp[*count].name, sizeof(emp[*count].name), stdin);
    emp[*count].name[strcspn(emp[*count].name, "\n")] = 0;
    printf("Enter Designation: ");
    fgets(emp[*count].designation, sizeof(emp[*count].designation), stdin);
    emp[*count].designation[strcspn(emp[*count].designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp[*count].salary);

    (*count)++;
    printf("\nEmployee added successfully!\n");
}
void displayEmployees(Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-20s $%-9.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
    }
    printf("-----------------------------------------------------------------\n");
}
void searchEmployee(Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == searchId) {
            printf("\nEmployee Found:\n");
            printf("-------------------------\n");
            printf("ID:          %d\n", emp[i].id);
            printf("Name:        %s\n", emp[i].name);
            printf("Designation: %s\n", emp[i].designation);
            printf("Salary:      $%.2f\n", emp[i].salary);
            printf("-------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}
void deleteEmployee(Employee emp[], int *count) {
    if (*count == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == deleteId) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                emp[j] = emp[j + 1];
            }
            (*count)--;
            printf("\nEmployee record deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", deleteId);
    }
}
