#include<stdio.h>
#include<math.h>


int main(){

    int n = 8;
    int v = (n&(n-1));
    printf("%d\n",v);
    

    int a='g';
    if(a>='a' && a<='z')
    {a=a^32;
    a=(char)a;    
    printf("%c\n",a);}

    int f = -5;
    f= f*f;
    f = sqrt(f);
    printf("absolute value = %d\n",f);

    int i=5;
    (i&1)?printf("odd\n"):printf("even\n");

    int q=9,w=10;
    int y=(q>w);
    printf("%d",y);

    return 0;
}