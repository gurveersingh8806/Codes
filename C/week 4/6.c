#include<stdio.h>

int main(){

    signed int a;
    a = sizeof(a);
    printf("size of signed int %d\n",a);

    unsigned int b;
    b = sizeof(b);
    printf("size of unsigned int %d\n",b);

    long int c;
    c = sizeof(c);
    printf("size of long int is %d\n",c);

    short int d;
    d = sizeof(d);
    printf("size of short int is %d\n",d);

    return 0;
}