#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int evalRPN(char** tokens, int tokensSize) {
    long stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];

        if (strlen(token) == 1 && !isdigit(token[0])) {
            long b = stack[top--];
            long a = stack[top--];

            switch (token[0]) {
                case '+':
                    stack[++top] = a + b;
                    break;
                case '-':
                    stack[++top] = a - b;
                    break;
                case '*':
                    stack[++top] = a * b;
                    break;
                case '/':
                    stack[++top] = a / b;
                    break;
            }
        } else {
            stack[++top] = atoi(token);
        }
    }

    return stack[top];
}