#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int price;
    struct Product* next;
    struct Product* prev;
};

struct Product* head = NULL;
struct Product* tail = NULL;
struct Product* current = NULL;

struct Product* createProduct(char name[], int price) {
    struct Product* newPro = (struct Product*)malloc(sizeof(struct Product));
    strcpy(newPro->name, name);
    newPro->price = price;
    newPro->next = newPro->prev = NULL;
    return newPro;
}

void addProduct(char name[], int price) {
    struct Product* newPro = createProduct(name, price);
    if (head== NULL) 
    head = tail = current = newPro;
    else {
        tail->next = newPro;
        newPro->prev = tail;
        tail = newPro;
        current = tail;
    }
}

void moveBackward() {
    if (current->prev != NULL) 
    current = current->prev;
    printf("Viewing: %s (%d)\n", current->name, current->price);
}

void moveForward() {
    if (current->next != NULL) 
    current = current->next;
    printf("Viewing: %s (%d)\n", current->name, current->price);
}

void deleteCheapProducts() {
    struct Product* temp = head;
    while (temp != NULL) {
        if (temp->price < 500) {
            struct Product* toDelete = temp;
            
            if (temp == head) 
            head = temp->next;
            if (temp == tail) 
            tail = temp->prev;            
            if (temp->prev != NULL) 
            temp->prev->next = temp->next;
            if (temp->next != NULL) 
            temp->next->prev = temp->prev;
            
            if (current == temp) 
            current = (temp->next != NULL ? temp->next : temp->prev);
            
            temp = temp->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }
}

void displayHistory() {
    struct Product* temp = head;
    while (temp != NULL) {
        printf("%s (%d) -> ", temp->name, temp->price);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayCurrent() {
    printf("Currently viewing: %s (%d)\n", current->name, current->price);
}

int main() {
    addProduct("Laptop", 800);
    addProduct("Mouse", 200);
    addProduct("Monitor", 1200);

    displayHistory();
    displayCurrent();

    moveBackward();
    moveForward();

    deleteCheapProducts();
    displayHistory();
    displayCurrent();

    return 0;
}
