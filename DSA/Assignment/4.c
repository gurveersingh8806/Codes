#include <stdio.h>
#include <stdlib.h>

#define TOT 1024

int A[TOT];
int top1 = -1;
int top2 = TOT;

int push1(int v){
    if(top1 + 1 == top2) return 0;
    A[++top1] = v;
    return 1;
}

int push2(int v){
    if(top2 - 1 == top1) return 0;
    A[--top2] = v;
    return 1;
}

int pop1(int *out){
    if(top1 < 0) return 0;
    *out = A[top1--];
    return 1;
}

int pop2(int *out){
    if(top2 >= TOT) return 0;
    *out = A[top2++];
    return 1;
}

int main(){
    int x;
    push1(10);
    push1(20);
    push2(30);
    push2(40);
    if(pop1(&x)) printf("popped1 %d\n", x);
    if(pop2(&x)) printf("popped2 %d\n", x);
    return 0;
}
