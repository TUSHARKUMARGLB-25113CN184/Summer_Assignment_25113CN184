/*Write a program to Print repeated character 
pattern. 
A 
BB 
CCC 
DDDD 
EEEEE*/
#include<stdio.h>
int main()
{
    int rows;
    printf("enter the number of rows: ");
    scanf("%d",&rows);
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=i;j++){
            printf("%c",i+64);
        }
        printf("\n");
    }
    return 0;
}