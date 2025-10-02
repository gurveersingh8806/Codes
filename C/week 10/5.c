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
    
    int m=0;
    for (int j=0;j<n;j++){
        for (int k=j+1;k<n;k++){
            if(A[j]>A[k]){
                m=A[j];
                A[j]=A[k];
                A[k]=m;
            }
            
        }
    }

    int k;
    printf("enter the value of k :\n");
    scanf("%d", &k);
    printf("the %dth largest number is : %d\n", k, A[n-k]);




    return 0;

}