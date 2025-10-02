#include<stdio.h>

int main (){

    int a,d,n;
    printf("enter inputs:");
    scanf("%d%d%d",&a,&d,&n);
    int s;
    for (int i=0;i<n;i++){
        s = a +(i*d);
        printf("%d",s);
        if(i<(n-1))
        {printf(", ");}
    }
    printf("\n");
    return 0;
}