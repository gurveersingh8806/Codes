#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

bool hascycle(ListNode* head, ListNode* &fast, ListNode* &slow) {

    if (head == NULL || head->next == NULL)
        return false;

    while (slow && fast) {

        fast = fast->next;
        if (fast)
            fast = fast->next;

        slow = slow->next;

        if (fast == slow)
            return true;
    }
    return false;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    head->next->next->next->next->next = head->next->next;

    ListNode* fast = head;
    ListNode* slow = head;

    if (!hascycle(head, fast, slow))
        cout << "no cycle present" << endl;

    else{ 
        slow = head;

        while(fast!= slow){ 
            fast = fast->next; slow = slow->next;
        }
        cout << "cycle present at node = "<< fast->val << endl; 
    }
}
