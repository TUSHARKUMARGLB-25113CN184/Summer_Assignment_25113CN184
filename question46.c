/*Write a program to Write function for 
Armstrong*/
#include<stdio.h>
int armstrong(int num){
    int originalNum, sum = 0, digit;
    originalNum = num;
    while (num != 0) {
        digit = num % 10; 
        sum += digit * digit * digit; 
        num = num / 10; 
    }
    if (originalNum == sum) {
        return 1; // It's an Armstrong number
    } else {
        return 0; // Not an Armstrong number
    }
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(armstrong(num)){
        printf("%d is an Armstrong number.",num);
    } else {
        printf("%d is not an Armstrong number.",num);
    }
    return 0;
}