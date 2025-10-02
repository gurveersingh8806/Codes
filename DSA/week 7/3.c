#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char expr[MAX];
    printf("Enter postfix expression: ");
    fgets(expr, MAX, stdin);

    char *token = strtok(expr, " \n");
    while(token != NULL) {
        if(isdigit(token[0])) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();

            
            int res;

            switch(token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            push(res);
        }
        token = strtok(NULL, " \n");
    }

    printf("Result = %d\n", pop());
    return 0;
}
