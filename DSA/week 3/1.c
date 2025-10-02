#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void insert(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
        printf("%d inserted\n", x);
    }
}

int delete() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void print() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        
        printf("\n");
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    print();

    printf("Deleted: %d\n", delete());
    print();

    return 0;
}
