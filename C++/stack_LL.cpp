#include<iostream>
using namespace std;


int top= -1;
int size = 100;

class stack{
    public:
    stack* next;
    int data;

    stack(int data){
        this->data = data;
        this->next = NULL;
    }

    void push(int data, stack* &tail, stack* &head){
        if(top < size){
            if(tail == NULL && top == -1){
                stack* temp = new stack(data);
                tail = temp;
                head = temp;
                top++;
                return;
            }
        stack* temp = new stack(data);
        tail->next = temp;
        tail = temp;
        top++;
        }
        else{cout << "Stack overflow"<< endl;}
    }

    void pop(stack* &tail,stack* &head){
        if(top >= 0){
            if(top == 0){ 
            delete head;
            head = tail = NULL;
            top--;
            return;
            }
            stack* temp = head;
            int pos = 1;
            while(pos < top){
                temp = temp->next;
                pos++;
            }
            tail = temp;
            temp = temp->next;
            tail->next = NULL;
            delete(temp);
            top--;
        }
        else{cout << "Stack underflow"<<endl;}
    }

    int peek(stack* &tail){
        if(top>= 0 ){
            return tail->data;
        }
        else{cout << "Stack is empty"<< endl;
        return -1;}
    }
    
    bool isempty(stack* &tail){
        return tail==NULL;
    }


};

int main(){

    stack s(0);
    stack* head = NULL;
    stack* tail = NULL;
    if(s.isempty(tail))
    cout << "yoo"<< endl;

    s.push(10,tail,head);
    s.push(20,tail,head);
    s.push(30,tail,head);
    cout << s.peek(tail)<<endl;
    s.pop(tail,head);
    cout << s.peek(tail)<<endl;


}