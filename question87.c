/*Write a program to Character frequency*/
#include <stdio.h>
#include <string.h>

void countFrequency(char str[]) {

    int freq[256] = {0}; 
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Frequency:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0 && i != ' ' && i != '\n' && i != '\t') {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }
}

int main() {
    char str[200];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    countFrequency(str);

    return 0;
}