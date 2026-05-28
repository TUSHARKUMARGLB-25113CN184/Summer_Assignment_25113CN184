/*Write a program to Print multiplication table of 
a given number*/
#include<stdio.h>
int main()
{
    int n,table=1;
    printf("enter the number: ");
    scanf("%d",&n);
    for(int i=1;i<=10;i++){
        table=i*n;
        printf("%d*%d=%d\n",n,i,table);
    }

    return 0;
}