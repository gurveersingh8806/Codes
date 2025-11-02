/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void insertattail(Node* &head, Node* &tail, int data){
        Node* newnode = new Node(data);

        if(head == NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    Node* copyRandomList(Node* head) {
        //1 create clone

        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }


        //2 add clone list in original

        Node* originalnode = head;
        Node* clonenode = clonehead;

        while(originalnode != NULL && clonenode != NULL){
            Node* next = originalnode->next;
            originalnode->next = clonenode;
            originalnode = next;

            next = clonenode->next;
            clonenode->next = originalnode;
            clonenode = next;
        }

        //3 add random pointers

        temp = head;

        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random  = temp->random ? temp -> random->next
                                        : temp->random;
            }
            temp = temp->next->next;
        }

        //4 revert changes

        originalnode = head;
        clonenode = clonehead;

        while(originalnode != NULL && clonenode != NULL){
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;

            if(originalnode != NULL)
            clonenode->next = originalnode->next;
            clonenode = clonenode->next;
        }

        //5 return ans

        return clonehead;
    }
};