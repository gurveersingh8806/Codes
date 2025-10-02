#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int main() {
    int n, i;
    printf("Enter number of coaches: ");
    scanf("%d", &n);

    int target[MAX];
    printf("Enter desired sequence: ");
    for(i=0; i<n; i++) {
        scanf("%d", &target[i]);
    }

    int next = 0; 
    for(i=1; i<=n; i++) {
        push(i);

        while(top >= 0 && peek() == target[next]) {
            pop();
            next++;
        }
    }

    if(next == n)
        printf("Yes, sequence possible\n");
    else
        printf("No, sequence not possible\n");

    return 0;
}
