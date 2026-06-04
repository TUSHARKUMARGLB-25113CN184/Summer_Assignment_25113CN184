/*Write a program to Print character triangle. 
A 
AB 
ABC 
ABCD 
ABCDE*/
#include<stdio.h>
int main(){
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%c",j+64);
        }
        printf("\n");
    }
}