/*Write a program to Write function for 
palindrome*/
#include<stdio.h>
int palindrome(int num){
     int originalNum, reversedNum = 0; 
    originalNum = num;  
    while (num != 0) {
        int digit = num % 10; 
        reversedNum = reversedNum * 10 + digit; 
        num = num / 10; 
    }
    if (originalNum == reversedNum) {
        return 1; // It's a palindrome
    } else {
        return 0; // Not a palindrome
    }
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(palindrome(num)){
        printf("%d is a palindrome.",num);
    } else {
        printf("%d is not a palindrome.",num);
    }
    return 0;
}