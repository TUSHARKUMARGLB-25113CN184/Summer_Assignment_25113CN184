/*Write a program to Sort words by length*/
#include <stdio.h>
#include <string.h>

void sortWordsByLength(char *str) {
    char words[20][50];
    int wordCount = 0;
    char *token = strtok(str, " ");
    while (token != NULL && wordCount < 20) {
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }
    char temp[50];
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
    printf("Words sorted by length:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%[^\n]s",str);

    printf("Original Sentence: %s\n\n", str);
    
    sortWordsByLength(str);

    return 0;
}