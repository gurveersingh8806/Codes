#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *top = NULL;

void push(int data) {
    Node *t = malloc(sizeof(Node));
    t->data = data;
    t->prev = NULL;
    t->next = top;
    if(top) top->prev = t;
    top = t;
}

int pop() {
    if(!top) return 0;
    int v = top->data;
    Node *tmp = top;
    top = top->next;
    if(top) top->prev = NULL;
    free(tmp);
    return v;
}

int get_element_from_top(int idx) {
    Node *curr = top;
    for(int i = 0; i < idx && curr; i++)
        curr = curr->next;
    return curr ? curr->data : 0;
}

int get_element_from_bottom(int idx) {
    Node *curr = top;
    if(!curr) return 0;
    while(curr->next) curr = curr->next;
    for(int i = 0; i < idx && curr; i++)
        curr = curr->prev;
    return curr ? curr->data : 0;
}

void print_stack(bool fromTop) {
    if(!top) return;
    if(fromTop) {
        Node *p = top;
        while(p) {
            printf("%d\n", p->data);
            p = p->next;
        }
    } else {
        Node *p = top;
        while(p && p->next) p = p->next;
        while(p) {
            printf("%d\n", p->data);
            p = p->prev;
        }
    }
}

int add() {
    int a = pop();
    int b = pop();
    int res = a + b;
    push(res);
    return res;
}

int subtract() {
    int a = pop();
    int b = pop();
    int res = b - a;
    push(res);
    return res;
}

int multiply() {
    int a = pop();
    int b = pop();
    int res = a * b;
    push(res);
    return res;
}

int divide() {
    int a = pop();
    int b = pop();
    int res = (a != 0) ? (b / a) : 0;
    push(res);
    return res;
}

Node* get_stack() {
    return top;
}

Node* search(Node *l, int x) {
    Node *curr = l;
    while(curr) {
        if(curr->data == x) return curr;
        curr = curr->next;
    }
    return NULL;
}

Node* srchinst(Node *l, int x) {
    Node *res = search(l, x);
    if(res) return res;
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->prev = NULL;
    n->next = l;
    if(l) l->prev = n;
    return n;
}

int main() {
    push(10);
    push(5);
    add();
    printf("Top: %d\n", top->data);

    Node *p = NULL;
    p = srchinst(p, 4);
    srchinst(p, 7);
    Node *f = search(p, 7);
    if(f) printf("Found %d\n", f->data);
    return 0;
}
