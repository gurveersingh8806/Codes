#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* create(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertatfront(struct node** head,struct node** tail,int data){

    struct node* newnode = create(data);
    if(*head == NULL){
        *head = newnode;
        *tail = newnode;
    }else{
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }

}

void insertattail(struct node** head,struct node** tail,int data){

    struct node* newnode = create(data);
    if(*head == NULL){
        *head = newnode;
        *tail = newnode;
    }else{
        newnode->prev = *tail;
        (*tail)->next = newnode;
        *tail = newnode;
    }

}

void print(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main(){
    struct node* head = NULL;
    struct node* tail = NULL;

    insertatfront(&head,&tail,3);
    insertatfront(&head,&tail,2);
    insertatfront(&head,&tail,1);
    insertattail(&head,&tail,4);
    insertattail(&head,&tail,5);
    printf("\nCompartments of the train:\n");
    print(head);
    
}
