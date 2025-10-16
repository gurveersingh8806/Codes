#include <stdio.h>
#include <stdlib.h>

#define SSIZE 50

typedef struct {
    int data[SSIZE];
    int top;
} Stack;

typedef struct node {
    Stack s;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void initS(Stack *st){
    st->top = -1;
}

void push(Stack *st, int x){
    if(st->top < SSIZE-1)
        st->data[++st->top] = x;
}

int pop(Stack *st){
    if(st->top < 0) return -1;
    return st->data[st->top--];
}

void enqueueS(Stack st){
    Node *n = malloc(sizeof(Node));
    n->s = st;
    n->next = NULL;
    if(!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

Stack dequeueS(){
    Stack dummy; initS(&dummy);
    if(!front) return dummy;
    Node *tmp = front;
    Stack out = tmp->s;
    front = front->next;
    if(!front) rear = NULL;
    free(tmp);
    return out;
}

int main(){
    Stack s1; initS(&s1);
    push(&s1, 5);
    push(&s1, 8);
    enqueueS(s1);

    Stack s2 = dequeueS();
    printf("%d\n", pop(&s2));
    return 0;
}
