#include<stdio.h>
#include<stdlib.h>

struct emp{

    char name[50];
    int salary;
    struct emp* next;
    
};

int main(){

    struct emp* start = NULL;
    struct emp* new = NULL, *temp= NULL;

    for(int i=0;i<10;i++){

        new = (struct emp*)malloc(sizeof(struct emp));

        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", new->name);
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%d", &new->salary);

        new->next = NULL;

        if (start == NULL) {
            start = new; 
        } else {
            temp->next = new;
        }
        temp = new;
    }

    temp = start;
    printf("\nEmployee List :\n");
    while(temp != NULL){
        printf("Name: %s, Salary: %d\n", temp->name, temp->salary);
        temp = temp->next;
    }

    temp = start;
    while(temp !=NULL){ 
        struct emp* delete = temp;
        temp = temp->next;
        free(delete);
    }

}