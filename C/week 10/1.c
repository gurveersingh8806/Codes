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
    printf("enter the index of the array element you want to print:\n ");
    int m;
    scanf("%d",&m);
    
    if(m<n)
    printf("the element is %d", A[m]);
    else
    printf("Invalid input.");
    
    

    return 0;

}