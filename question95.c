/*Write a program to Find longest word*/
#include <stdio.h>
#include <string.h>

void findLongestWord(const char *str) {
    int len = strlen(str);
    int maxLength = 0;  
    int maxStartIndex = 0;
    
    int currentLength = 0;   
    int currentStartIndex = 0; 
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStartIndex = currentStartIndex;
            }
            currentStartIndex = i + 1;
            currentLength = 0;
        } else {
            currentLength++;
        }
    }
    printf("Longest Word: ");
    for (int i = maxStartIndex; i < maxStartIndex + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\nLength: %d\n", maxLength);
}

int main() {
    char str[100];
    printf("enter string: ");
    scanf("%s",&str);

    printf("Sentence: %s\n", str);
    findLongestWord(str);

    return 0;
}