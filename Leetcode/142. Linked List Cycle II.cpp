/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

     bool hasCycle(ListNode *head,ListNode* &fast,ListNode* &slow) {
        

        if(head == NULL || head->next == NULL)
        return false;

        while(slow != NULL && fast != NULL){
            fast = fast->next;
            if(fast!= NULL)
            fast = fast->next;

            slow = slow->next;

            if(fast == slow)
            return true;

            
        }
        return false;
    }


    ListNode *detectCycle(ListNode *head) {

        ListNode *fast = head;
        ListNode *slow = head;

        if (head == NULL){
            return NULL;
        }

        if(!hasCycle(head,fast,slow))
        return NULL;
        else{
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            return fast;
        }

        
    }
};