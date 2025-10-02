#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createStop(char name[]) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    strcpy(n->name, name);
    return n;
}

void insertStop(char name[], int pos) {
    struct Node* n = createStop(name);
    if (head == NULL) {
        head = n;
        head->next = head;
        head->prev = head;
        return;
    }
    struct Node* temp = head;
    for (int i=1; i<pos-1; i++) 
    temp = temp->next;

    n->next = temp->next;
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;

    if (pos == 1) 
    head = n;  
}

void deleteStop(char name[]) {
    struct Node* temp = head;
    do {
        if (strcmp(temp->name, name) == 0) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head)
            head = temp->next;
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void displayForward() {
    struct Node* temp = head;
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

void displayBackward() {
    struct Node* temp = head->prev;
    do {
        printf("%s -> ", temp->name);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("...\n");
}

int main() {
    insertStop("StopA", 1);
    insertStop("StopB", 2);
    insertStop("StopC", 3);
    insertStop("StopD", 2);

    displayForward();
    displayBackward();

    deleteStop("StopB");

    displayForward();
    displayBackward();
    return 0;
}
