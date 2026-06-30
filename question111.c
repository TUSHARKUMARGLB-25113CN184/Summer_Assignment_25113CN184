/*Write a program to Create ticket booking 
system*/
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5
#define TICKET_PRICE 12.00 
typedef struct {
    int totalTicketsBooked;
    double totalRevenue;
} TheaterStats;

// Function Prototypes
void displaySeating(char seats[ROWS][COLS]);
void bookTicket(char seats[ROWS][COLS], TheaterStats *stats);
void checkSeat(char seats[ROWS][COLS]);
void displayStats(TheaterStats stats);

int main() {
    char seats[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 'A'; 
        }
    }

    TheaterStats stats = {0, 0.0};
    int choice;

    printf("--- Welcome to the Movie Ticket Booking System ---\n");

    while (1) {
        printf("\n===================================\n");
        printf("1. View Seating Chart\n");
        printf("2. Book a Ticket\n");
        printf("3. Check Seat Availability\n");
        printf("4. View Sales & Revenue Summary\n");
        printf("5. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                displaySeating(seats);
                break;
            case 2:
                bookTicket(seats, &stats);
                break;
            case 3:
                checkSeat(seats);
                break;
            case 4:
                displayStats(stats);
                break;
            case 5:
                printf("\nThank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}
void displaySeating(char seats[ROWS][COLS]) {
    printf("\n\t     [ SCREEN HERE ]\n\n");
    printf("       ");
    for (int j = 0; j < COLS; j++) {
        printf("Col %d  ", j + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d:  ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf(" [%c]   ", seats[i][j]);
        }
        printf("\n");
    }
    printf("\nLegend: [A] = Available, [B] = Booked\n");
}

void bookTicket(char seats[ROWS][COLS], TheaterStats *stats) {
    int row, col;
    
    displaySeating(seats);
    printf("Enter Row number (1-%d): ", ROWS);
    scanf("%d", &row);
    printf("Enter Column number (1-%d): ", COLS);
    scanf("%d", &col);
    int r = row - 1;
    int c = col - 1;

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("\nError: Invalid row or column selection!\n");
        return;
    }
    if (seats[r][c] == 'B') {
        printf("\nError: Seat Row %d, Col %d is already Booked!\n", row, col);
    } else {
        seats[r][c] = 'B';
        stats->totalTicketsBooked += 1;
        stats->totalRevenue += TICKET_PRICE;
        
        printf("\nSuccess: Seat Row %d, Col %d booked successfully!\n", row, col);
        printf("Ticket Price: $%.2f added to total bill.\n", TICKET_PRICE);
    }
}
void checkSeat(char seats[ROWS][COLS]) {
    int row, col;
    printf("\nEnter Row and Column to check (e.g., 2 3): ");
    scanf("%d %d", &row, &col);

    int r = row - 1;
    int c = col - 1;

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Error: Coordinates are out of bounds.\n");
        return;
    }

    if (seats[r][c] == 'A') {
        printf("Seat Row %d, Col %d is AVAILABLE.\n", row, col);
    } else {
        printf("Seat Row %d, Col %d is BOOKED.\n", row, col);
    }
}
void displayStats(TheaterStats stats) {
    printf("\n====== Theater Business Summary ======\n");
    printf("Total Tickets Sold: %d\n", stats.totalTicketsBooked);
    printf("Total Revenue Generated: $%.2f\n", stats.totalRevenue);
    printf("======================================\n");
}