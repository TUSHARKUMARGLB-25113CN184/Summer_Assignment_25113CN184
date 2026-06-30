/*Write a program to Create inventory 
management system*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50
#define LOW_STOCK_THRESHOLD 5 
typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    double price;
} Item;
void addItem(Item inventory[], int *itemCount);
void displayInventory(const Item inventory[], int itemCount);
void searchItem(const Item inventory[], int itemCount);
void updateStock(Item inventory[], int itemCount);
void checkLowStock(const Item inventory[], int itemCount);
int findItemIndex(const Item inventory[], int itemCount, int id);

int main() {
    Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    printf("--- Welcome to the Inventory Management System ---\n");

    while (1) {
        printf("\n===================================\n");
        printf("1. Add New Item\n");
        printf("2. Display Current Inventory\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Stock Quantity\n");
        printf("5. Check Low Stock Alerts\n");
        printf("6. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                displayInventory(inventory, itemCount);
                break;
            case 3:
                searchItem(inventory, itemCount);
                break;
            case 4:
                updateStock(inventory, itemCount);
                break;
            case 5:
                checkLowStock(inventory, itemCount);
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}
void addItem(Item inventory[], int *itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("\nError: Inventory tracking limit reached. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("\nEnter unique Item ID (Integer): ");
    scanf("%d", &newItem.id);
    getchar(); 
    if (findItemIndex(inventory, *itemCount, newItem.id) != -1) {
        printf("Error: Item with ID %d already exists.\n", newItem.id);
        return;
    }

    printf("Enter Item Name: ");
    fgets(newItem.name, NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; 

    printf("Enter Initial Quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter Unit Price: $");
    scanf("%lf", &newItem.price);

    if (newItem.quantity < 0 || newItem.price < 0) {
        printf("Error: Quantity and Price cannot be negative numbers!\n");
        return;
    }

    inventory[*itemCount] = newItem;
    (*itemCount)++;

    printf("\nSuccess: Item \"%s\" added to inventory!\n", newItem.name);
}
void displayInventory(const Item inventory[], int itemCount) {
    if (itemCount == 0) {
        printf("\nThe inventory is currently empty.\n");
        return;
    }

    double totalInventoryValue = 0;

    printf("\n%-10s %-25s %-10s %-12s %-15s\n", "Item ID", "Item Name", "Stock", "Unit Price", "Total Value");
    printf("---------------------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        double totalValue = inventory[i].quantity * inventory[i].price;
        totalInventoryValue += totalValue;

        printf("%-10d %-25s %-10d $%-11.2f $%-14.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price,
               totalValue);
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Total Active Inventory Valuation: $%.2f\n", totalInventoryValue);
}
void searchItem(const Item inventory[], int itemCount) {
    int id;
    printf("\nEnter Item ID to look up: ");
    scanf("%d", &id);

    int index = findItemIndex(inventory, itemCount, id);
    if (index == -1) {
        printf("Error: Item ID %d not found.\n", id);
        return;
    }

    printf("\n--- Item Details ---");
    printf("\nID:            %d", inventory[index].id);
    printf("\nName:          %s", inventory[index].name);
    printf("\nStock Level:   %d units", inventory[index].quantity);
    printf("\nUnit Price:    $%.2f", inventory[index].price);
    printf("\nTotal Worth:   $%.2f\n", inventory[index].quantity * inventory[index].price);
}
void updateStock(Item inventory[], int itemCount) {
    int id, updateChoice;
    printf("\nEnter Item ID to update stock: ");
    scanf("%d", &id);

    int index = findItemIndex(inventory, itemCount, id);
    if (index == -1) {
        printf("Error: Item ID %d not found.\n", id);
        return;
    }

    printf("\nCurrent Stock for \"%s\" is %d units.\n", inventory[index].name, inventory[index].quantity);
    printf("1. Restock (Add units)\n2. Dispatch (Remove units)\nSelect operation (1-2): ");
    scanf("%d", &updateChoice);

    int amount;
    if (updateChoice == 1) {
        printf("Enter number of units to add: ");
        scanf("%d", &amount);
        if (amount > 0) {
            inventory[index].quantity += amount;
            printf("Success: Updated stock level. New count: %d units.\n", inventory[index].quantity);
        } else {
            printf("Error: Quantity must be greater than zero.\n");
        }
    } else if (updateChoice == 2) {
        printf("Enter number of units to remove: ");
        scanf("%d", &amount);
        if (amount > 0) {
            if (amount > inventory[index].quantity) {
                printf("Error: Stock underflow! Not enough items in stock to fulfill demand.\n");
            } else {
                inventory[index].quantity -= amount;
                printf("Success: Updated stock level. New count: %d units.\n", inventory[index].quantity);
            }
        } else {
            printf("Error: Quantity must be greater than zero.\n");
        }
    } else {
        printf("Invalid choice. Operation cancelled.\n");
    }
}
void checkLowStock(const Item inventory[], int itemCount) {
    int alertCount = 0;
    
    printf("\n--- Low Stock Alerts (Threshold: < %d units) ---\n", LOW_STOCK_THRESHOLD);
    printf("%-10s %-25s %-10s\n", "Item ID", "Item Name", "Current Stock");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].quantity < LOW_STOCK_THRESHOLD) {
            printf("%-10d %-25s %-10d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
            alertCount++;
        }
    }

    if (alertCount == 0) {
        printf("Excellent: All item stock levels are healthy!\n");
    } else {
        printf("\nWarning: %d item(s) require immediate reordering.\n", alertCount);
    }
}
int findItemIndex(const Item inventory[], int itemCount, int id) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            return i; 
        }
    }
    return -1;
}