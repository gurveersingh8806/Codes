#include<stdio.h>

int main(){

    float n;
    printf("enter number:");
    scanf("%f",&n);

    int d1, d2;

    d1 = (int)n%10;
    n = n/10;

    d2 = (int)n%10;
    n = n/10;

    printf("the last two integral digits of the given number are %d and %d ", d1, d2);
    return 0;
}