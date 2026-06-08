/*Write a program to Write function for perfect 
number*/
#include<stdio.h>
int perfect(int num){   
    int sum = 0;
    for(int i=1; i<num; i++){
        if(num % i == 0){
            sum += i;
        }
    }
    if(sum == num){
        return 1; // It's a perfect number
    } else {
        return 0; // Not a perfect number
    }
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(perfect(num)){
        printf("%d is a perfect number.",num);
    } else {
        printf("%d is not a perfect number.",num);
    }
    return 0;
}