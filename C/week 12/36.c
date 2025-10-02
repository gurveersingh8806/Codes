#include<stdio.h>
int number(char *p,int n){
    int c = 0;
    for(int i = 0;i<n;i++){
        if(i!=n-1 && p[i]=='O' && p[i+1]=='H')
            c++;
    }
    return c;
}
int main(){
    
    char compound[]= "CCOHHHOHOHOHOH";
    printf("number of OH in your compound: %d", number(compound,sizeof(compound)));
}