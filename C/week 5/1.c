#include<stdio.h>

int main(){
    
    int a = 6, b = 9, c = 14, f = 1;
    int g = (a!= 7&&f||c>=6);
    int h = (!(b>=12)&&a%2 == 0);
    int j =  (!(a>5||c<a+b));
    printf("g= %d\n",g);
    printf("h= %d\n",g);
    printf("j= %d\n",j);

    c = a+b||f;
    printf("c= %d",c);

    
    return 0;

}