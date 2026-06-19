#include <stdio.h>
#include <string.h>
void sortString(char* str, int len) {
    char temp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

char getMaxOccurringCharSorted(char* str) {
    int len = strlen(str);
    if (len == 0) return '\0';
    sortString(str, len);

    char maxChar = str[0];
    int maxCount = 1;
    
    char currentChar = str[0];
    int currentCount = 1;
    for (int i = 1; i < len; i++) {
        if (str[i] == str[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxChar = currentChar;
            }
            currentChar = str[i];
            currentCount = 1;
        }
    }
    if (currentCount > maxCount) {
        maxCount = currentCount;
        maxChar = currentChar;
    }

    return maxChar;
}

int main() {
    char str[100];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    
    char maxChar = getMaxOccurringCharSorted(str);
    printf("Maximum occurring character is: '%c'\n", maxChar);
    
    return 0;
}