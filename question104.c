/*Write a program to Create quiz application*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char questions[][200] = {
        "1. Which programming language is known as the 'mother of all languages'?",
        "2. What is the size of an 'int' data type in C (usually on a 32/64-bit system)?",
        "3. Which keyword is used to prevent any changes to a variable in C?",
        "4. What is the correct file extension for a standard C source code file?"
    };
    char options[][200] = {
        "A) Python\tB) C\nC) Java\t\tD) Assembly",
        "A) 1 Byte\tB) 2 Bytes\nC) 4 Bytes\tD) 8 Bytes",
        "A) static\tB) volatile\nC) immutable\tD) const",
        "A) .cpp\t\tB) .c\nC) .exe\t\tD) .obj"
    };
    char correctAnswers[] = {'B', 'C', 'D', 'B'};
    
    int totalQuestions = sizeof(correctAnswers) / sizeof(correctAnswers[0]);
    int score = 0;
    char userGuess;

    printf("========================================\n");
    printf("       WELCOME TO THE TECH QUIZ!        \n");
    printf("========================================\n");
    printf("Instructions: Answer by typing A, B, C, or D.\n\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("----------------------------------------\n");
        printf("%s\n\n", questions[i]);
        printf("%s\n", options[i]);
        printf("----------------------------------------\n");

        while (1) {
            printf("Your Answer: ");
            if (scanf(" %c", &userGuess) != 1) {
                printf("Invalid Input! Please try again.\n");
                while (getchar() != '\n'); 
                continue;
            }
            userGuess = toupper(userGuess);
            if (userGuess == 'A' || userGuess == 'B' || userGuess == 'C' || userGuess == 'D') {
                break; 
            } else {
                printf("🚨 Invalid Option! Please choose from A, B, C, or D.\n");
            }
        }
        if (userGuess == correctAnswers[i]) {
            printf("\n Correct!\n\n");
            score++;
        } else {
            printf("\n Incorrect! The correct answer was %c.\n\n", correctAnswers[i]);
        }
    }
    printf("========================================\n");
    printf("             QUIZ COMPLETED!            \n");
    printf("========================================\n");
    printf("Your Final Score: %d out of %d\n", score, totalQuestions);
    double percentage = ((double)score / totalQuestions) * 100;
    printf("Percentage Obtained: %.2f%%\n", percentage);
    if (score == totalQuestions) {
        printf("Performance: Excellent! Perfect score! \n");
    } else if (score >= totalQuestions / 2) {
        printf("Performance: Good job! Pass.\n");
    } else {
        printf("Performance: Needs Improvement. Better luck next time!\n");
    }
    printf("========================================\n");

    return 0;
}