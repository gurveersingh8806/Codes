#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    if(top < MAX-1) {
        stack[++top] = c;
    }
}

char pop() {
    if(top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if(top >= 0) return stack[top];
    return '\0';
}

int main() {
    char code[MAX];
    printf("Enter code snippet:\n");
    fgets(code, MAX, stdin);

    int i, len = strlen(code);
    int inComment = 0;

    for(i=0; i<len; i++) {
        if(!inComment && code[i]=='/' && code[i+1]=='*') {
            inComment = 1;
            i++;
            continue;
        }

        if(inComment && code[i]=='*' && code[i+1]=='/') {
            inComment = 0;
            i++;
            continue;
        }

        if(inComment) continue;

        if(code[i]=='(' || code[i]=='{' || code[i]=='[') {
            push(code[i]);
        }
        else if(code[i]==')') {
            if(peek()=='(') pop(); else break;
        }
        else if(code[i]=='}') {
            if(peek()=='{') pop(); else break;
        }
        else if(code[i]==']') {
            if(peek()=='[') pop(); else break;
        }
    }

    if(top==-1 && !inComment)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
