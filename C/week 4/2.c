#include<stdio.h>

int main(){
    
    float a,u,t;

    printf("enter acceleration:");
    scanf("%f",&a);
    printf("enter initial velocity:");
    scanf("%f",&u);
    printf("enter time:");
    scanf("%f",&t);

    float S;
    S = (u*t) + (0.5*a*t*t);
    printf("the displacement is %f",S);
    
    
    return 0;

}

