#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][20]; 
int top = -1;

void push(char func[]) {
    strcpy(stack[++top], func);
    printf("Call: %s()\n", func);
}

void pop() {
    if(top != -1) {
        printf("Return: %s()\n", stack[top]);
        top--;
    }
}

int main() {
    push("main");   
    push("A");      
    push("B");      
    push("C");      

    pop(); 
    pop(); 
    pop(); 
    pop(); 

    return 0;
}
