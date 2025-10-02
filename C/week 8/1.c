#include<stdio.h>

int main (){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);

    while(n>1){

        if(n%2==0){
            n = n/2;
            printf("%d\t",n );
        }
        else{
            n = (3*n + 1);
            printf("%d\t",n);
        }
    }




    return 0;
}