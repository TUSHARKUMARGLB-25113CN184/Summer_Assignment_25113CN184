/*Write a program to Compress a string*/
#include <stdio.h>
#include <string.h>

void compressString(const char *str) {
    int len = strlen(str);
    if (len == 0) {
        return;
    }

    printf("Compressed String: ");
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("enter string: ");
    scanf("%s",str);

    printf("Original String: %s\n", str);
    compressString(str);

    return 0;
}