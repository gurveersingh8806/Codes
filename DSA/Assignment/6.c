#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* search(Node *l, int x) {
    Node *curr = l;
    while(curr) {
        if(curr->data == x)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

Node* srchinst(Node *l, int x) {
    Node *ptr = search(l, x);
    if(ptr) return ptr;

    Node *newnode = malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = l;
    return newnode;
}

int main() {
    Node *head = NULL;
    head = srchinst(head, 5);
    head = srchinst(head, 9);
    head = srchinst(head, 4);

    Node *p = search(head, 9);
    if(p) printf("Found: %d\n", p->data);

    return 0;
}
