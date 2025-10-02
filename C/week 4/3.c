#include<stdio.h>

int main(){

    int n;
    printf("enter a 5 digit number:");
    scanf("%5d",&n);

    int d1,d2,d3,d4,d5;
    d1 = n%10;
    n = n/10;

    d2 = n%10;
    n = n/10;

    d3 = n%10;
    n = n/10;

    d4 = n%10;
    n = n/10;

    d5 = n%10;

    int sum = d1 + d2 + d3 + d4 + d5;
    printf("the sum of the digits is %d",sum);

    return 0;
}