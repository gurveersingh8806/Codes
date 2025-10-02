#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertAtPosition(struct node** head, struct node** tail, int value, int pos) {
    struct node* newNode = create(value);

    if (pos == 1) { 
        newNode->next = *head;
        *head = newNode;
        if (*tail == NULL) *tail = newNode; 
        return;
    }

    struct node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        *tail = newNode;  
    }
}

void deleteAtPosition(struct node** head, struct node** tail, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = *head;

    if (pos == 1) {  
        *head = temp->next;
        if (*head == NULL) *tail = NULL;
        free(temp);
        return;
    }

    struct node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    if (temp->next == NULL) {
        *tail = prev;
    }
    free(temp);
}

void print(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;

    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct node* newnode = create(value);

        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    int c;
    while (1) {
        printf("\nMenu:\n 1.Insert element\n 2.Delete element\n 3.Show List\n 4.Exit\nChoice: ");
        scanf("%d", &c);
        switch (c) {
            case 1: {
                int position, data;
                printf("Enter position and data: ");
                scanf("%d%d", &position, &data);
                insertAtPosition(&head, &tail, data, position);
                break;
            }
            case 2: {
                int position;
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, &tail, position);
                break;
            }
            case 3:
                print(head);
                break;
            case 4:
                printf("End of program.\n");
                exit(0);
        }
    }
}
