/*Write a program to Develop complete mini 
project using arrays, strings and functions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
typedef struct {
    int id;
    char title[100];
    char author[50];
    int isIssued;
} Book;
void addBook(Book library[], int *count);
void displayBooks(Book library[], int count);
void searchBook(Book library[], int count);
void issueBook(Book library[], int count);
void returnBook(Book library[], int count);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;
    library[0] = (Book){101, "The C Programming Language", "Dennis Ritchie", 0};
    library[1] = (Book){102, "To Kill a Mockingbird", "Harper Lee", 0};
    library[2] = (Book){103, "1984", "George Orwell", 1};
    bookCount = 3;

    while (1) {
        printf("\n=======================================\n");
        printf("      LIBRARY MANAGEMENT SYSTEM        \n");
        printf("=======================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

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
                printf("\nExiting system. Have a great day!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}
void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("\nError: Library catalog is full!\n");
        return;
    }

    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &library[*count].id);
    getchar();

    printf("Enter Book Title: ");
    fgets(library[*count].title, sizeof(library[*count].title), stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0;
    printf("Enter Author Name: ");
    fgets(library[*count].author, sizeof(library[*count].author), stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0;

    library[*count].isIssued = 0; 

    (*count)++;
    printf("\nBook successfully added to the catalog!\n");
}
void displayBooks(Book library[], int count) {
    if (count == 0) {
        printf("\nThe library is completely empty right now.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("%-7s %-35s %-25s %-12s\n", "ID", "Title", "Author", "Status");
    printf("-----------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-7d %-35s %-25s %-12s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isIssued ? "Issued" : "Available");
    }
    printf("-----------------------------------------------------------------------------------------\n");
}
void searchBook(Book library[], int count) {
    if (count == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    char searchTitle[100];
    int found = 0;

    getchar();
    printf("\nEnter the Book Title to search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    printf("\nSearch Results:\n");
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0 || strstr(library[i].title, searchTitle) != NULL) {
            printf("- [%d] %s by %s (%s)\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].isIssued ? "Borrowed" : "Available");
            found = 1;
        }
    }

    if (!found) {
        printf("No books matched the title \"%s\".\n", searchTitle);
    }
}
void issueBook(Book library[], int count) {
    int targetId, found = 0;
    
    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &targetId);

    for (int i = 0; i < count; i++) {
        if (library[i].id == targetId) {
            found = 1;
            if (library[i].isIssued == 1) {
                printf("\nSorry, \"%s\" is already borrowed.\n", library[i].title);
            } else {
                library[i].isIssued = 1;
                printf("\nSuccess! \"%s\" has been issued to you.\n", library[i].title);
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook ID %d not found in the system.\n", targetId);
    }
}
void returnBook(Book library[], int count) {
    int targetId, found = 0;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &targetId);

    for (int i = 0; i < count; i++) {
        if (library[i].id == targetId) {
            found = 1;
            if (library[i].isIssued == 0) {
                printf("\nThis book is already sitting on the library shelf!\n");
            } else {
                library[i].isIssued = 0;
                printf("\nSuccess! Thank you for returning \"%s\".\n", library[i].title);
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook ID %d does not match our catalog records.\n", targetId);
    }
}