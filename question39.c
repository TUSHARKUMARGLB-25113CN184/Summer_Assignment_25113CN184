/*Write a program to Print number pyramid    
    1  
   121  
  12321 
 1234321 
123454321 */
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
                printf("%d",k);
            }
            else{
                printf("%d",2*i-k);
            }
        }
        printf("\n");
    }
    return 0;
}