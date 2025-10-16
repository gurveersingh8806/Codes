#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stk[1024];
int top = -1;

void push(int v){ if(top < 1023) stk[++top] = v; }
int pop(){ return top>=0 ? stk[top--] : 0; }

int main(){
    char line[4096];
    if(!fgets(line, sizeof line, stdin)) return 0;
    char *tok = strtok(line, " \t\n");
    while(tok){
        char *endptr;
        long val = strtol(tok, &endptr, 10);
        if(*endptr == '\0'){
            push((int)val);
        } else {
            int b = pop();
            int a = pop();
            int r = 0;
            if(tok[0] == '+') r = a + b;
            else if(tok[0] == '-') r = a - b;
            else if(tok[0] == '*') r = a * b;
            else if(tok[0] == '/') r = b ? a / b : 0;
            push(r);
        }
        tok = strtok(NULL, " \t\n");
    }
    if(top >= 0) printf("%d\n", stk[top]);
    return 0;
}
