#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

void undo(char name[],int *n){
    stack[++top] = name[*n-1];
    name[*n-1] = '\0';
    (*n)--;
    return;
}

void redo(char name[],int *n, int length){

    if(*n>0 && *n < length){
        name[*n] = stack[top--];
        (*n)++;
        name[*n] = '\0';
        return;
    }
}

int main(){

    char name[50];
    printf("Enter name:\n");
    fgets(name, sizeof(name), stdin);
    int n = strlen(name);
    int length = n;
    if (length > 0 && name[length - 1] == '\n') {
    name[length - 1] = '\0';
}


    printf("You entered : ");
    printf("%s",name);

    int c;

    while(1){ 
            printf("\nWhat do you want to do?\n");
            printf("1. Undo 2. Redo 3. Exit\n");
            scanf("%d",&c);
        switch(c){

            case 1 : {undo(name,&n);
                printf("%s",name);
                break;}
            case 2 :  {redo(name,&n,length);
                printf("%s",name);
                break;}
            case 3 : {printf("End of Code.\n");
            exit(0);}

        }
    }
}
