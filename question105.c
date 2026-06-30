/* Write a program to Create student record 
management system*/
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
struct Student {
    int rollNumber;
    char name[50];
    float gpa;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    int searchRoll;
    int found;

    printf("========================================\n");
    printf("   STUDENT RECORD MANAGEMENT SYSTEM     \n");
    printf("========================================\n");

    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid choice! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                if (studentCount >= MAX_STUDENTS) {
                    printf("\n System Full! Cannot add more student records.\n");
                } else {
                    printf("\n--- Enter Student Details ---\n");
                    printf("Enter Roll Number: ");
                    scanf("%d", &students[studentCount].rollNumber);
                    while (getchar() != '\n'); 
                    
                    printf("Enter Student Name: ");
                    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
                    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;

                    printf("Enter GPA: ");
                    scanf("%f", &students[studentCount].gpa);

                    studentCount++;
                    printf("\n Record added successfully!\n");
                }
                break;

            case 2:
                if (studentCount == 0) {
                    printf("\n No student records found in the database.\n");
                } else {
                    printf("\n==================================================\n");
                    printf("%-10s %-25s %-5s\n", "Roll No", "Name", "GPA");
                    printf("==================================================\n");
                    for (int i = 0; i < studentCount; i++) {
                        printf("%-10d %-25s %-5.2f\n", 
                               students[i].rollNumber, 
                               students[i].name, 
                               students[i].gpa);
                    }
                    printf("==================================================\n");
                }
                break;

            case 3:
                if (studentCount == 0) {
                    printf("\n The database is empty. Add records first.\n");
                } else {
                    printf("\nEnter Roll Number to search: ");
                    scanf("%d", &searchRoll);
                    found = 0;

                    for (int i = 0; i < studentCount; i++) {
                        if (students[i].rollNumber == searchRoll) {
                            printf("\n🎉 Record Found!\n");
                            printf("-----------------------------------\n");
                            printf("Roll Number : %d\n", students[i].rollNumber);
                            printf("Name        : %s\n", students[i].name);
                            printf("GPA         : %.2f\n", students[i].gpa);
                            printf("-----------------------------------\n");
                            found = 1;
                            break; 
                        }
                    }
                    if (!found) {
                        printf("\n Student with Roll Number %d not found.\n", searchRoll);
                    }
                }
                break;

            case 4:
                printf("\n========================================\n");
                printf("    Exiting System. Have a good day!    \n");
                printf("========================================\n");
                break;

            default:
                printf("\n Invalid option! Please select a valid menu choice (1-4).\n");
        }

    } while (choice != 4);

    return 0;
}