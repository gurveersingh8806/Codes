#include <stdio.h>
#include <stdlib.h>

#define QSIZE 50

typedef struct {
    int data[QSIZE];
    int front, rear;
} Queue;

typedef struct node {
    Queue q;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

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

void enqueueQ(Queue q){
    Node *n = malloc(sizeof(Node));
    n->q = q;
    n->next = NULL;
    if(!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

Queue dequeueQ(){
    Queue dummy; initQ(&dummy);
    if(!front) return dummy;
    Node *tmp = front;
    Queue out = tmp->q;
    front = front->next;
    if(!front) rear = NULL;
    free(tmp);
    return out;
}

int main(){
    Queue q1; initQ(&q1);
    enqueue(&q1, 2);
    enqueue(&q1, 4);
    enqueueQ(q1);

    Queue q2 = dequeueQ();
    printf("%d\n", dequeue(&q2));
    return 0;
}
