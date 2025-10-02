#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[20];
    struct Node* next;
};

struct Node* newNode(char* n) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    strcpy(t->name, n);
    t->next = NULL;
    return t;
}

void addEnd(struct Node** head, char* n) {
    struct Node* t = newNode(n);
    if (*head == NULL) {
        *head = t;
        return;
    }
    struct Node* cur = *head;
    while (cur->next != NULL)
    cur = cur->next;

    cur->next = t;
}

void addLuggageSecond(struct Node** head) {
    if (*head == NULL) {
        printf("No engine. Luggage goes as first coach.\n");
        *head = newNode("Luggage");
        return;
    }
    struct Node* t = newNode("Luggage");
    t->next = (*head)->next;
    (*head)->next = t;
}

void addLuggageEnd(struct Node** head) {
    if (*head == NULL) {
        printf("No engine! Luggage goes as first coach.\n");
        *head = newNode("Luggage");
        return;
    }
    addEnd(head, "Luggage");
}

void show(struct Node* head) {
    struct Node* cur = head;
    printf("Train:\n");
    while (cur) {
        printf("[%s]--", cur->name);
        cur = cur->next;
    }
    printf("NULL\n\n");
}

int main() {
    struct Node* train = NULL;

    addEnd(&train, "Engine");
    addEnd(&train, "C1");
    addEnd(&train, "C2");
    show(train);

    addLuggageSecond(&train);
    show(train);

    addLuggageEnd(&train);
    show(train);

    return 0;
}

