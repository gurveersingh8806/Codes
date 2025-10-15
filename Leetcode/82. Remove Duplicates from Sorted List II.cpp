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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* num = new ListNode(-191);
        num->next = head;
        head = num;
        ListNode* curr = head;
        ListNode* prev = head;
        ListNode* temp = curr;


        while(curr != NULL){

            if((curr->next != NULL)  && (curr->val == curr->next->val) ){
                while(temp!= NULL && temp->val == curr->val){
                    temp = temp->next;
                }
                prev->next = temp;
                curr = temp;
            }
            else{
                prev= curr;
                curr = curr->next;
                temp = curr;
            }

        }

        return head->next;



    }
};