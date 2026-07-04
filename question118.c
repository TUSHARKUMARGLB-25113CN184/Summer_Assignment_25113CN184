/*Write a program to Create mini library 
system*/
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int isbn;
    int isAvailable;
};

struct Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Maximum number of books reached.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[bookCount].title);

    printf("Enter book author: ");
    scanf("%s", books[bookCount].author);

    printf("Enter book ISBN: ");
    scanf("%d", &books[bookCount].isbn);

    books[bookCount].isAvailable = 1;
    bookCount++;
}

void displayBooks() {
    printf("\nBook Records:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("ISBN: %d\n", books[i].isbn);
        printf("Available: %s\n", books[i].isAvailable ? "Yes" : "No");
        printf("--------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
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
