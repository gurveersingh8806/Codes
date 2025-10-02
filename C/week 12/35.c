#include<stdio.h>
int palindrome(char *p, int n){
    int c = 1;
    for(int i  = 0;i<n/2;i++){
        if(p[i]!=p[n-1-i]){
            c = 0;
            break;
        }
    }
    return c;
}
int main(){
    
    char fullName[] = "hello";
    if(palindrome(fullName,5)){
        printf("ok1");
    } 
    char ok[]= "yay";
    if(palindrome(ok,3)){
        printf("ok2");
    }
}