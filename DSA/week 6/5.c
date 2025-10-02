#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[50];
    int pri;
    struct Node *next, *prev;
} Node;

Node* newNode(int id, char* name, int pri) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->id = id;
    n->pri = pri;
    strcpy(n->name, name);
    n->next = n->prev = NULL;
    return n;
}

void insert(Node** head, Node* n) {
    if (!*head || (*head)->pri >= n->pri) {
        n->next = *head;
        if (*head) (*head)->prev = n;
        *head = n;
    } else {
        Node* curr = *head;
        while (curr->next && curr->next->pri < n->pri) {
            curr = curr->next;
        }
        n->next = curr->next;
        if (n->next) n->next->prev = n;
        curr->next = n;
        n->prev = curr;
    }
}

void del(Node** head, int id) {
    Node* curr = *head;
    while (curr && curr->id != id) {
        curr = curr->next;
    }
    if (!curr) return; 

    if (curr->prev) curr->prev->next = curr->next;
    else *head = curr->next; 
    if (curr->next) curr->next->prev = curr->prev;
    free(curr);
}

void printList(Node* n) {
    printf("ID\tName\tPriority\n");
    while (n) {
        printf("%d\t%s\t%d\n", n->id, n->name, n->pri);
        n = n->next;
    }
}

int main() {
    Node* list = NULL;
    insert(&list, newNode(101, "Alice", 3));
    insert(&list, newNode(102, "Bob", 1));
    insert(&list, newNode(103, "Charlie", 4));
    insert(&list, newNode(104, "Diana", 2));
    printList(list);

    printf("\nDeleting patient 102...\n");
    del(&list, 102);
    printList(list);
    
    return 0;
}
