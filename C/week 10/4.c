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
    printf("array:\n");
    for(int i=0;i<n;i++){
        printf("%d,",A[i]);
    }
    int m=0;
    for (int j=0;j<n;j++){
        for (int k=j+1;k<n-j;k++){
            if(A[k]>A[k+1]){
                m=A[k];
                A[k]=A[k+1];
                A[k+1]=m;
            }
            
        }
        
    }

    printf("\nfinal array:\n");
    for(int i=0;i<n;i++){
        printf("%d,",A[i]);
    }

    return 0;

}