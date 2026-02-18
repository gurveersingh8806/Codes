#include <bits/stdc++.h>
using namespace std;

struct Node {
    float data;
    Node* next;

    Node(float x) {
        data = x;
        next = NULL;
    }
};

void insert(Node*& head, float val) {
    Node* newNode = new Node(val);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

Node* bucketSort(Node* head) {

    if (!head || !head->next)
        return head;

    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    vector<vector<float>> bucket(n);

    temp = head;

    while (temp) {
        int idx = temp->data * n;   
        bucket[idx].push_back(temp->data);
        temp = temp->next;
    }

    for (int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    temp = head;

    for (int i = 0; i < n; i++) {
        for (float val : bucket[i]) {
            temp->data = val;
            temp = temp->next;
        }
    }

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        float x;
        cin >> x;
        insert(head, x);
    }

    head = bucketSort(head);

    printList(head);

    return 0;
}
