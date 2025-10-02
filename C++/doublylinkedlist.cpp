#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;
    node* prev;

    node(int data){
        
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~node (){
        if(this-> next != NULL){
            this->next = NULL;
            delete next;
        }
    }
};

void insertathead(node* &head, int data){

    node* temp = new node(data);
    temp ->next = head;
    head -> prev = temp;
    head = temp;

}

void insertattail(node* &tail, int data){

    node* temp = new node(data);
    tail -> next = temp;
    temp -> prev = tail;
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
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;

}

void deletenodebypos(node* &head,node* &tail, int position){

    if(position == 1){
        node* temp = head; 
        temp-> next->prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
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
    crnt-> prev = NULL;
    crnt->next= NULL;

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

int getlength(node* &head){

    node* temp = head;
    int length =0;
    while(temp != NULL){
        length++;
        temp = temp-> next;  
    }
    return length;
}

int main(){

    node* node1 = new node(10);

    node* head = node1;
    node* tail = node1;

    insertathead(head,12);
    insertattail(tail,8);

    insertatposition(head,tail,3,15);
    print(head);

    deletenodebypos(head,tail,4 );
    print(head);

    cout << tail ->data ;
}
