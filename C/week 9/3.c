#include<stdio.h>

int main(){

    int *a, *b;
    int c,d;

    a=&c;
    b=&d;

    scanf("%d%d",&c,&d);

    printf("sum = %d\n", *a + *b);
    printf("difference = %d\n", *a - *b);
    printf("product = %d\n", *a * *b);

    if(d!=0){
    printf("division = %d\n", *a / *b);
    printf(" modulus = %d\n", *a % *b);
    }
    else
    printf("Invalid Input\n");

    return 0;
    
    


}