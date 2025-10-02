#include <stdio.h>
#include <string.h>

int main(){

    int a[3][3]= {1,2,3,4,5,6,7,8,9};

        
    int srow = 0;
    int erow = 2;
    int scol = 0;
    int ecol = 2 ;
    int count = 0;

    while(count<9){

        for(int i=scol;i<=ecol && count<9; i++){
            printf("%d ",a[srow][i]);
            count++;
        }
        srow++;
        for(int i=srow;i<=erow && count<9; i++){
            printf("%d ",a[i][ecol]);
            count++;
            
        }
        ecol--;
        for(int i=ecol;i>=scol && count<9; i--){
            printf("%d ",a[erow][i]);
            count++;
            
        }
        erow--;
        for(int i=erow;i>=srow && count<9; i--){
            printf("%d ",a[i][scol]);
            count++;
            
        }
        scol++;


    }
        
    }





