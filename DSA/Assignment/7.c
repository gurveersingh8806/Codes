#include <stdio.h>
#include <string.h>

#define SIZE 1000

char stk[SIZE];
int top = -1;

void push(char c){
    if(top < SIZE - 1)
        stk[++top] = c;
}

char pop(){
    if(top >= 0)
        return stk[top--];
    return '\0';
}

int main(){
    char str[SIZE];
    scanf("%s", str);

    int len = strlen(str);
    for(int i = 0; i < len; i++)
        push(str[i]);

    int ok = 1;
    for(int i = 0; i < len; i++){
        if(str[i] != pop()){
            ok = 0;
            break;
        }
    }

    if(ok)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
