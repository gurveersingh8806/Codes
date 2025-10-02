#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

void insertFront(struct Node** head, char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node** head, char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertKnown(struct Node** head, char* name, int k) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL || k <= 0) {
        insertEnd(head, name);
        return;
    }

    int len = 0;
    struct Node* temp = *head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    int pos = len - k;
    if (pos < 0) pos = 0; 

    if (pos == 0) {
        insertFront(head, name);
        return;
    }

    temp = *head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayQueue(struct Node* head) {
    printf("Queue:\n");
    while (head != NULL) {
        printf("%s -> ", head->name);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* queue = NULL;

    insertEnd(&queue, "Person1");
    insertEnd(&queue, "Person2");
    insertFront(&queue, "VIP1");
    insertKnown(&queue, "Known1", 2);
    insertEnd(&queue, "Person3");
    insertFront(&queue, "VIP2");
    displayQueue(queue);

}
