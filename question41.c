/*Write a program to Write function to find sum 
of two numbers */
#include<stdio.h>
int sum(int a,int b){
    return a+b;
}
int main(){
    int num1,num2;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);
    printf("Sum of %d and %d is %d",num1,num2,sum(num1,num2));
    return 0;
}
