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

    ListNode* reverseList(ListNode* head) {
        ListNode* crnt = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(crnt != NULL){
            forward = crnt->next;
            crnt-> next = prev;
            prev = crnt;
            crnt = forward;
        } 

        return prev;

        
    }

    ListNode* add(ListNode* l1, ListNode* l2){

        int carry = 0;
        int sum = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode *ans = new ListNode(-1);
        ListNode *temp3 = ans;

        while(temp1 != NULL && temp2 != NULL){
            sum = temp1->val + temp2->val + carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            temp3->next = temp;
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }

        while(temp1 != NULL){
            sum = temp1->val + carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            temp3->next = temp;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }

         while(temp2 != NULL){
            sum = temp2->val + carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            temp3->next = temp;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }

        if(carry == 1){
            ListNode* temp = new ListNode(1);
            temp3->next = temp;
        }

        return ans;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* ans = add(l1,l2);

        ans = reverseList(ans);
        ListNode* node = ans; 
        while(node->next->val != -1){ 
            node = node->next; 
        }
        
        node->next = NULL; 
        return ans;
        
    }
};