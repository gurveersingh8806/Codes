#include<iostream>
using namespace std;

class node {
public:
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};

node* createList(int arr[], int n) {
    if (n == 0) return NULL;

    node* head = new node(arr[0]);
    node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
    return head;
}

node* findmid(node* head){

    node* fast = head->next;
    node* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node* left, node* right){

    if(left == NULL)
    return right;

    if(right == NULL)
    return left;

    node* dummy = new node(-99999);
    node* temp = dummy;

    while(left && right){
        if(left->val < right->val){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right->next;
        }

    }

    while(left){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right){
        temp -> next = right;
        temp = right;
        right = right->next;
    }

    dummy = dummy->next;
    return dummy;


}

node* mergesort(node* head){

    if(head == NULL || head->next == NULL)
    return head;

    node* mid = findmid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergesort(left);
    right = mergesort(right);

    node* result = merge(left,right);

    return result;

}



int main(){

    int arr[] = {2, 3, 1, 8, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    node* head = createList(arr, n);

    cout << "Original Linked List : "<< endl;
    node* temp1 = head;
    while(temp1){
        cout << temp1->val << " -> " ;
        temp1 = temp1->next;
    }
    cout << endl;
    

    head = mergesort(head);

    node* temp = head;

    cout << "Sorted Linked List : "<< endl;
    while(temp){
        cout << temp->val << " -> " ;
        temp = temp->next;
    }
    cout << endl;
    


}