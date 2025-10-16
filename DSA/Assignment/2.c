#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *arr;
    int cap;
    int top;
} DStack;

DStack S;

void init_stack(){
    S.cap = 1024;
    S.arr = malloc(sizeof(int) * S.cap);
    S.top = -1;
}

void resize(int newcap){
    int *tmp = realloc(S.arr, sizeof(int)*newcap);
    if(tmp){
        S.arr = tmp;
        S.cap = newcap;
    }
}

void push(int v){
    if(S.top + 1 == S.cap) resize(S.cap * 2);
    S.arr[++S.top] = v;
}

int pop(){
    int v = S.top >= 0 ? S.arr[S.top--] : 0;
    if(S.cap > 1024 && S.top + 1 <= S.cap/4) resize(S.cap/2);
    return v;
}

int main(){
    init_stack();
    char line[8192];
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
    if(S.top >= 0) printf("%d\n", S.arr[S.top]);
    free(S.arr);
    return 0;
}
