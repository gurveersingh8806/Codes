#include<stdio.h>

int main(){

    int d;
    printf("enter inches:");
    scanf("%d",&d);

    int v,w,x,y,z;

    v = d/(8*220*3*12);
    d = d%(8*220*3*12);

    w = d/(220*3*12);
    d = d%(220*3*12);

    x = d/(3*12);
    d = d%(3*12);

    y = d/12;
    d = d%12;

    z = d;

    printf("The distance is %d miles, %d furlongs, %d yards, %d feet, and %d inches.",v,w,x,y,z);
    


    return 0;
}