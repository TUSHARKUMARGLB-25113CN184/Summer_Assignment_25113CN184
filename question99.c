/*Write a program to Sort names 
alphabetically*/
#include <stdio.h>
#include <string.h>

void sortNames(char names[][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() 
   {
    int n;
    
    printf("Enter the number of names: ");
    scanf("%d", &n);
    
    char names[100][50];
    
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    
    printf("Original List of Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
    sortNames(names, n);

    printf("\nAlphabetically Sorted Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}