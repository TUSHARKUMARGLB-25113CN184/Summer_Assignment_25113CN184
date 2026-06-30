/*Write a program to Create employee 
management system*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};
void addEmployee(struct Employee emp[], int *count);
void displayEmployees(struct Employee emp[], int count);
void searchEmployee(struct Employee emp[], int count);
void updateEmployee(struct Employee emp[], int count);

int main() {
    struct Employee empList[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n=================================");
        printf("\n1. Add New Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Update Employee Details");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(empList, &employeeCount);
                break;
            case 2:
                displayEmployees(empList, employeeCount);
                break;
            case 3:
                searchEmployee(empList, employeeCount);
                break;
            case 4:
                updateEmployee(empList, employeeCount);
                break;
            case 5:
                printf("\nExiting the program. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nDatabase full! Cannot add more employees.\n");
        return;
    }

    printf("\n--- Add New Employee ---\n");
    printf("Enter Employee ID: ");
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

void displayEmployees(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n-------------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
    }
    printf("-------------------------------------------------------------------\n");
}

void searchEmployee(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == searchId) {
            printf("\n--- Employee Found ---\n");
            printf("ID: %d\n", emp[i].id);
            printf("Name: %s\n", emp[i].name);
            printf("Designation: %s\n", emp[i].designation);
            printf("Salary: %.2f\n", emp[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}


void updateEmployee(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    int updateId, found = 0;
    printf("\nEnter Employee ID to update details: ");
    scanf("%d", &updateId);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == updateId) {
            printf("\n--- Current Details of ID %d ---\n", emp[i].id);
            printf("Name: %s | Designation: %s | Salary: %.2f\n", emp[i].name, emp[i].designation, emp[i].salary);
            
            printf("\nEnter New Details:\n");
            getchar();
            
            printf("Enter New Name: ");
            fgets(emp[i].name, sizeof(emp[i].name), stdin);
            emp[i].name[strcspn(emp[i].name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp[i].designation, sizeof(emp[i].designation), stdin);
            emp[i].designation[strcspn(emp[i].designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp[i].salary);

            printf("\nEmployee details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", updateId);
    }
}
