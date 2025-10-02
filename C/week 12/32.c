#include<stdio.h>
int countdigit(int n){
    int c = 0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}
int power(int n, int r){
    if(r==0)
        return 1;
    else
        return n*power(n,r-1);
}

int reverse(int n){
    if(n==0)
        return 0;
    else
        return (n%10)*(int)(power(10,countdigit(n)-1)) + reverse(n/10);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("reversed : %d ", reverse(n));
}