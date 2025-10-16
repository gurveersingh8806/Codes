#include <stdio.h>
#include <stdlib.h>

#define QSIZE 50
#define MAXSTACK 10

typedef struct {
    int data[QSIZE];
    int front, rear;
} Queue;

Queue stack[MAXSTACK];
int top = -1;

void initQ(Queue *q){
    q->front = q->rear = -1;
}

void enqueue(Queue *q, int x){
    if(q->rear == QSIZE-1) return;
    if(q->front == -1) q->front = 0;
    q->data[++q->rear] = x;
}

int dequeue(Queue *q){
    if(q->front == -1 || q->front > q->rear) return -1;
    return q->data[q->front++];
}

void pushQ(Queue q){
    if(top < MAXSTACK-1)
        stack[++top] = q;
}

Queue popQ(){
    if(top < 0){
        Queue dummy; initQ(&dummy);
        return dummy;
    }
    return stack[top--];
}

int main(){
    Queue q1; initQ(&q1);
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    pushQ(q1);

    Queue q2 = popQ();
    printf("%d\n", dequeue(&q2));
    return 0;
}
