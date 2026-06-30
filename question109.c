/*Write a program to Create library 
management system*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50
typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int is_issued;
} Book;
void displayMenu();
void addBook(Book library[], int *bookCount);
void displayBooks(const Book library[], int bookCount);
void searchBook(const Book library[], int bookCount);
void issueBook(Book library[], int bookCount);
void returnBook(Book library[], int bookCount);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    printf("--- Welcome to the Library Management System ---\n");

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                issueBook(library, bookCount);
                break;
            case 5:
                returnBook(library, bookCount);
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}
void displayMenu() {
    printf("\n===================================\n");
    printf("1. Add New Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book by Title\n");
    printf("4. Issue a Book\n");
    printf("5. Return a Book\n");
    printf("6. Exit\n");
    printf("===================================\n");
}

void addBook(Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("\nError: Library space is full!\n");
        return;
    }

    Book newBook;
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &newBook.id);
    getchar();
    for (int i = 0; i < *bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("Error: A book with ID %d already exists.\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    printf("Enter Author Name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; 

    newBook.is_issued = 0; 

    library[*bookCount] = newBook;
    (*bookCount)++;

    printf("\nSuccess: Book added successfully!\n");
}
void displayBooks(const Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nThe library is currently empty.\n");
        return;
    }

    printf("\n%-10s %-25s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-25s %-25s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}
void searchBook(const Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nThe library is empty. Nothing to search.\n");
        return;
    }

    char searchTitle[TITLE_LEN];
    printf("\nEnter the Title of the book to search: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            if (!found) {
                printf("\nBook found:\n");
                printf("%-10s %-25s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
                printf("-------------------------------------------------------------------------\n");
            }
            printf("%-10d %-25s %-25s %-15s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo book found with the title \"%s\".\n", searchTitle);
    }
}
void issueBook(Book library[], int bookCount) {
    int id, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued == 1) {
                printf("\nSorry, this book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("\nSuccess: Book \"%s\" has been issued.\n", library[i].title);
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}
void returnBook(Book library[], int bookCount) {
    int id, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued == 0) {
                printf("\nThis book is already marked as available in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nSuccess: Book \"%s\" returned successfully.\n", library[i].title);
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}