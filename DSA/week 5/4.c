#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insert(struct node** head, int val) {
    struct node* newnode = create(val);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newnode;
}

void display(struct node* table[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        struct node* temp = table[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct node* table[6] = {NULL};  
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        int idx = val % 6;
        insert(&table[idx], val);
    }

    display(table, 6);
    return 0;
}
