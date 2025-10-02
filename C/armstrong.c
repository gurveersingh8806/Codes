#include<stdio.h>
#include<math.h>

int main (){

    int num,digit=0;
    int a,sum=0;
    printf("enter num\n");
    scanf("%d",&num);
    int numb=num;
    int numbb=num;
    
    while(num!=0){
        num/=10;
        digit++;
    }
    while(numb!=0){
        a = numb%10;
        sum = sum + pow(a,digit);
        numb = numb/10;

    }
    if (sum == numbb)
    printf("number is armstrong");
    else
    printf("number is not armstrong");



    return 0;

}