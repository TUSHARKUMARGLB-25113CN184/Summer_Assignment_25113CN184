/*Write a program to Create number guessing 
game*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess;
    int attempts = 0;
    srand(time(NULL));
    secretNumber = (rand() % 100) + 1;

    printf("========================================\n");
    printf("   Welcome to the Number Guessing Game  \n");
    printf("========================================\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Try to guess it!\n\n");
    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Error: Invalid input! Please enter a number.\n\n");
            while (getchar() != '\n');
            continue; 
        }

        attempts++; 
        if (guess < 1 || guess > 100) {
            printf("Out of range! Please guess between 1 and 100.\n\n");
        } 
        else if (guess > secretNumber) {
            printf("Too high! Try a smaller number.\n\n");
        } 
        else if (guess < secretNumber) {
            printf("Too low! Try a larger number.\n\n");
        } 
        else {
            printf("========================================\n");
            printf("Congratulations! You found the secret number.\n");
            printf("The number was %d.\n", secretNumber);
            printf("You guessed it in %d attempts.\n", attempts);
            printf("========================================\n");
        }

    } while (guess != secretNumber);

    return 0;
}