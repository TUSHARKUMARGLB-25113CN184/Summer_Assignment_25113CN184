/*Write a program to Print character pyramid  
    A 
   ABA 
  ABCBA 
 ABCDCBA 
ABCDEDCBA */
#include<stdio.h>
int main()
{
    int rows,i,j,k;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=rows-i;j++)
        {
            printf(" ");
        }
        for(k=1;k<=2*i-1;k++){
            if(k<=i){
                printf("%c",k+64);
            }
            else{
                printf("%c",2*i-k+64);
            }
        }
        printf("\n");
    }
    return 0;
}