#include<stdio.h>

int main(){

int num,original,reverse=0,digit;
printf("enter num \n");
scanf("%d",&num);
original = num;
while(num!=0){

    digit = num%10;
    reverse = reverse*10 + digit;
    num /=10;
}

if(original == reverse)
printf("the number is palindrome");
else 
printf("the number is not palindrome");

return 0;


}