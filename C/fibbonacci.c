#include<stdio.h>

int main (){

    int a = 1;
    int b = 1;
    int c;
    int n;
    printf("enter n\n");
    scanf("%d",&n);

    int i=1;
    while(i<=n){
        printf("%d ",a);
        c = b + a;
        a = b;
        b = c;
        i++;


    }


    return 0;
}