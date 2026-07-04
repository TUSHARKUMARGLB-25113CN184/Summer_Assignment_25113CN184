/*Write a program to Create student record 
system using arrays and strings*/
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_GRADE_LENGTH 10

struct Student {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    char grade[MAX_GRADE_LENGTH];
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[studentCount].name);

    printf("Enter student roll number: ");
    scanf("%d", &students[studentCount].rollNumber);

    printf("Enter student grade: ");
    scanf("%s", students[studentCount].grade);

    studentCount++;
}

void displayStudents() {
    printf("\nStudent Records:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Grade: %s\n", students[i].grade);
        printf("--------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nStudent Record System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
