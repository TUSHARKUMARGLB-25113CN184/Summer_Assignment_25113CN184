/*Write a program to Create marksheet 
generation system*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
struct Student {
    int rollNo;
    char name[50];
    float marks[5]; 
    float total;
    float percentage;
    char grade[5];
};

// Function declarations
void addStudentMarks(struct Student s[], int *count);
void displayAllMarksheets(struct Student s[], int count);
void generateIndividualMarksheet(struct Student s[], int count);
char* calculateGrade(float percentage);

int main() {
    struct Student studentList[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {

        printf("\n=================================");
        printf("\n=== MARKSHEET GENERATION SYSTEM ===");
        printf("\n=================================");
        printf("\n1. Add Student Marks");
        printf("\n2. Display All Student Summary");
        printf("\n3. Generate Individual Marksheet (Report Card)");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentMarks(studentList, &studentCount);
                break;
            case 2:
                displayAllMarksheets(studentList, studentCount);
                break;
            case 3:
                generateIndividualMarksheet(studentList, studentCount);
                break;
            case 4:
                printf("\nExiting the system. All the best!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please pick an option from 1 to 4.\n");
        }
    }
    return 0;
}
char* calculateGrade(float percentage) {
    if (percentage >= 90) return "A+";
    else if (percentage >= 80) return "A";
    else if (percentage >= 70) return "B";
    else if (percentage >= 60) return "C";
    else if (percentage >= 50) return "D";
    else if (percentage >= 40) return "E";
    else return "Fail";
}
void addStudentMarks(struct Student s[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase Full!\n");
        return;
    }

    printf("\n--- Enter Student Details ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &s[*count].rollNo);

    getchar();

    printf("Enter Student Name: ");
    fgets(s[*count].name, sizeof(s[*count].name), stdin);
    s[*count].name[strcspn(s[*count].name, "\n")] = 0; 

    printf("\nEnter Marks out of 100:\n");
    s[*count].total = 0; 
    
    char subjects[5][20] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Sci"};
    
    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("%s: ", subjects[i]);
            scanf("%f", &s[*count].marks[i]);
        
            if (s[*count].marks[i] >= 0 && s[*count].marks[i] <= 100) {
                s[*count].total += s[*count].marks[i];
                break;
            } else {
                printf("Invalid marks! Please enter between 0 and 100.\n");
            }
        }
    }

    s[*count].percentage = (s[*count].total / 500.0) * 100.0;
    strcpy(s[*count].grade, calculateGrade(s[*count].percentage));

    (*count)++;
    printf("\nMarks added and calculated successfully!\n");
}
void displayAllMarksheets(struct Student s[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n---------------------------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-15s %-10s\n", "Roll No", "Student Name", "Total (/500)", "Percentage (%)", "Grade");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-12.2f %-15.2f %-10s\n", 
               s[i].rollNo, s[i].name, s[i].total, s[i].percentage, s[i].grade);
    }
    printf("---------------------------------------------------------------------------------\n");
}
void generateIndividualMarksheet(struct Student s[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    int searchRoll, found = 0;
    printf("\nEnter Student Roll Number to generate Report Card: ");
    scanf("%d", &searchRoll);

    char subjects[5][20] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Sci"};

    for (int i = 0; i < count; i++) {
        if (s[i].rollNo == searchRoll) {
            printf("\n==================================================");
            printf("\n                PROGRESS REPORT CARD             ");
            printf("\n==================================================");
            printf("\n Roll Number : %-15d Name : %s", s[i].rollNo, s[i].name);
            printf("\n--------------------------------------------------");
            printf("\n %-25s | %-15s", "Subject Name", "Marks Obtained");
            printf("\n--------------------------------------------------");
            
            for (int j = 0; j < 5; j++) {
                printf("\n %-25s | %-15.2f", subjects[j], s[i].marks[j]);
            }
            
            printf("\n--------------------------------------------------");
            printf("\n GRAND TOTAL         : %.2f / 500.00", s[i].total);
            printf("\n AGGREGATE PERCENTAGE: %.2f %%", s[i].percentage);
            printf("\n FINAL GRADE         : %s", s[i].grade);
            printf("\n==================================================\n");
            
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", searchRoll);
    }
}