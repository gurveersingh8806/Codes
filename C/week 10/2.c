#include<stdio.h>

int main(){

    printf("Enter n:\n");
    int n;
    scanf("%d",&n);
    int A[n];
    printf("enter the values of array elements:\n");

    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    int ecount=0,ocount=0;
    for(int j=0;j<n;j++){
        if((A[j])%2==0)
        ecount++;
        else
        ocount++;
    }

    printf("no. of even elements: %d\n", ecount);
    printf("no. of odd elements : %d\n", ocount);

    return 0;

}