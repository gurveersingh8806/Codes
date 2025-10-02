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
            this -> next = NULL;
            delete next;
        }
    }

};

void insertathead(node* &head, int data){

    node* temp = new node(data);
    temp ->next = head;
    head = temp;

}

void insertattail(node* &tail, int data){
    node* temp = new node(data);
    tail -> next = temp;
    tail = temp ;
}

void insertatposition(node* &head, node* &tail, int pos, int data){

    if(pos == 1){
        insertathead(head,data);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count < pos - 1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertattail(tail,data);
        return;
    }

    node* nodetoinsert = new node(data);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;

}

void deletenodebypos(node* &head,node* &tail, int position){

    if(position == 1){
        node* temp = head; 
        head = head -> next;
        delete temp;
        return;
    }

    int count =1;
    node* crnt = head;
    node* prev = NULL;

    while(count < position){
        prev = crnt;
        crnt = crnt -> next;
        count++;
    }

    prev -> next = crnt -> next;

    if(crnt -> next == NULL)
    tail = prev;

    delete crnt;
}

void deletenodebyval(node* &head ,node* &tail, int val){

    if(head ->data == val){
        node* temp = head; 
        head = head -> next;
        delete temp;
        return;
    }

    node* crnt = head;
    node* prev = NULL;

    while(crnt != NULL && crnt ->data != val){
        prev = crnt;
        crnt = crnt -> next;
    }

    prev -> next = crnt -> next;

    if(crnt -> next == NULL)
    tail = prev;

    delete crnt;
    
    
}

void print(node* &head){

    node* temp = head;
    while(temp != NULL){
        cout << temp ->data << " ";
        temp = temp-> next;
        
    }
    cout << endl;
}

int main(){

    node* node1 = new node(10);

    node* head = node1;
    node* tail = node1;

    insertattail(tail,12);
    insertattail(tail,15);

    insertatposition(head,tail,3,22);
    print(head);

    deletenodebypos(head,tail,1);
    print(head);



}
