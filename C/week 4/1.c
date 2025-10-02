#include<stdio.h>

int main(){

    float x;
    printf("enter amount:");
    scanf("%f",&x);

    int r100,r50,r10,r5,r2,r1,p50;

    r100 = x/100;
    x = x-(r100*100);

    r50 = x/50;
    x = x-(r50*50);

    r10 = x/10;
    x = x-(r10*10);

    r5 = x/5;
    x = x-(r5*5);

    r2 = x/2;
    x = x-(r2*2);

    r1 = x/1;
    x = x-(r1*1);

    p50 = x/0.5;

    printf("there are %d 100rs, %d 50rs, %d 10rs, %d 5rs, %d 2rs, %d 1rs, %d 50p in the amount given",r100,r50,r10,r5,r2,r1,p50);


    return 0;
}