/*Write a program to Create contact 
management system*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 50
typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;
void addContact(Contact book[], int *count);
void displayContacts(const Contact book[], int count);
void searchContact(const Contact book[], int count);
void deleteContact(Contact book[], int *count);

int main() {
    Contact addressBook[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    printf("--- Welcome to the Contact Management System ---\n");

    while (1) {
        printf("\n===================================\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 

        switch (choice) {
            case 1:
                addContact(addressBook, &contactCount);
                break;
            case 2:
                displayContacts(addressBook, contactCount);
                break;
            case 3:
                searchContact(addressBook, contactCount);
                break;
            case 4:
                deleteContact(addressBook, &contactCount);
                break;
            case 5:
                printf("\nExiting Address Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}
void addContact(Contact book[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("\nError: Address book is full!\n");
        return;
    }

    Contact newContact;

    printf("\nEnter Contact Name: ");
    fgets(newContact.name, NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;

    printf("Enter Phone Number: ");
    fgets(newContact.phone, PHONE_LEN, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;

    printf("Enter Email Address: ");
    fgets(newContact.email, EMAIL_LEN, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0;
    book[*count] = newContact;
    (*count)++;

    printf("\nSuccess: Contact added successfully!\n");
}
void displayContacts(const Contact book[], int count) {
    if (count == 0) {
        printf("\nYour address book is empty.\n");
        return;
    }

    printf("\n%-25s %-15s %-30s\n", "Name", "Phone Number", "Email Address");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("------- %-25s %-15s %-30s\n", book[i].name, book[i].phone, book[i].email);
    }
}
void searchContact(const Contact book[], int count) {
    if (count == 0) {
        printf("\nThe address book is empty. Nothing to search.\n");
        return;
    }

    char searchName[NAME_LEN];
    printf("\nEnter the exact name of the contact to search: ");
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, searchName) == 0) {
            if (!found) {
                printf("\nContact found:\n");
                printf("%-25s %-15s %-30s\n", "Name", "Phone Number", "Email Address");
                printf("----------------------------------------------------------------------\n");
            }
            printf("%-25s %-15s %-30s\n", book[i].name, book[i].phone, book[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo matching contact found for \"%s\".\n", searchName);
    }
}
void deleteContact(Contact book[], int *count) {
    if (*count == 0) {
        printf("\nThe address book is empty. Nothing to delete.\n");
        return;
    }

    char deleteName[NAME_LEN];
    printf("\nEnter the exact name of the contact to delete: ");
    fgets(deleteName, NAME_LEN, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0;

    int foundIndex = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(book[i].name, deleteName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nError: Contact matching \"%s\" not found.\n", deleteName);
        return;
    }
    for (int i = foundIndex; i < (*count) - 1; i++) {
        book[i] = book[i + 1];
    }

    (*count)--; 
    printf("\nSuccess: Contact \"%s\" has been deleted.\n", deleteName);
}