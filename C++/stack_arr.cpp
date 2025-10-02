#include<iostream>
using namespace std;

class stack{

  public:
  int top;
  int size;
  int *arr;

  stack(int size){
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int value){
    if(top < size){
      arr[++top] = value;
    }
    else{
      cout<<"Stack overflow"<< endl;
    }
  }

  void pop(){
    if(top >=0){
      top--;
    }
    else{
      cout<<"Stack underflow"<<endl;
    }
  }

  int peek(){
    if(top>=0){
      return arr[top];
    }
    else{
      cout << "Stack is empty"<< endl;
    }
  }

  bool isempty(){
    if(top == -1){
      return true;
    }
    return false;
  }

};

int main(){

  stack s(10);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  cout << s.peek() << endl;
  s.pop();
  s.pop();
  cout << s.peek() << endl;



}
