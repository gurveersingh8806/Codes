#include<stdio.h>

int main(){

    float n;
    printf("enter number:");
    scanf("%f",&n);

    int d1, d2;
    int n1,n2;
    n = n - (int)n;
    n = n*10;
    n1 = (int)n;
    d1 = n1%10;
    n = n*10;

    n2 = (int)n;
    d2 = n2%10;

    

    printf("the first two fractional digits of the given number are %d and %d ", d1, d2);
    return 0;
}