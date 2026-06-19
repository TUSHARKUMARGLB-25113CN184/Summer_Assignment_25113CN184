/*Write a program to Count words in a 
sentence*/
#include <stdio.h>

int countWords(char str[]) {
    int i = 0;
    int words = 0;
    int inWord = 0; 
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            inWord = 0;
        }
        else if (inWord == 0) {
            inWord = 1;
            words++;
        }
        i++;
    }
    return words;
}

int main() {
    char sentence[200];

    printf("Enter a one sentence:  ");
    
    fgets(sentence, sizeof(sentence), stdin);


    int totalWords = countWords(sentence);
    printf("Total words: %d\n", totalWords);

    return 0;
}