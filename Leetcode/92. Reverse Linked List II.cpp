/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head || left == right) return head;

        ListNode* temp = head;
        int count = 1;

        if(left == 1){
            temp = NULL;
        }else{
        while(count<left-1){
            temp = temp->next;
            count++;
        }
        }

        ListNode* temp1 = (temp) ? temp->next : head;
        ListNode* prev = NULL;
        ListNode* curr = temp1;
        ListNode* forw = NULL;

        count = left;

        while(count<=right && curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;

        }

        if (temp) 
        temp->next = prev;
        else 
        head = prev;
        
        temp1->next = forw;
        
        return head;


    }
};