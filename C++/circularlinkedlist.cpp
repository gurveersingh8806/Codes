#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int data){
        
        this->data = data;
        this->next = NULL;
    }

    ~node(){
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
    }

};

void insertnode(node* &tail,int element, int data){

    if(tail == NULL){
        node *temp = new node(data);
        tail = temp;
        temp->next = temp;
        return;
    }
    else{
        node* crnt = tail;

        while(crnt->data != element){
            crnt = crnt-> next;
        }

        node *temp = new node(data);
        temp->next = crnt->next;
        crnt->next = temp;
    }
}

void print(node* tail){

    node *temp = tail; 
    if(tail == NULL){
        cout << "list is empty" << endl;
        return;
    }


    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail);
    cout << endl; 
}

void deletenode(node* &tail,int element){

    if(tail == NULL){
        cout << "list is empty" << endl;
        return;
    }

    node* crnt = tail->next;
    node* prev =  tail;

    while(crnt->data != element){

        prev = crnt;
        crnt = crnt->next;
    }

    prev->next = crnt->next;

    if(crnt == prev)
    tail = NULL;

    else if(tail == crnt)
    tail = prev;

    crnt->next = NULL;

    delete crnt;
}

int main(){

    node* tail = NULL;

    insertnode(tail,1,1);
    print(tail);

    //insertnode(tail,1,3);
    //print(tail);

    // insertnode(tail,3,5);
    // print(tail);

    // insertnode(tail,1,7);
    // print(tail);

    deletenode(tail,1);
    print(tail);

}