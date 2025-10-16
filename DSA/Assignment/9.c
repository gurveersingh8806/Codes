#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node* findIntersection(struct Node* headA, struct Node* headB) {
    if (!headA || !headB) {
        return NULL;
    }

    struct Node *pA = headA;
    struct Node *pB = headB;
    int lenA = 0, lenB = 0;

    while (pA) {
        lenA++;
        pA = pA->next;
    }

    while (pB) {
        lenB++;
        pB = pB->next;
    }

    pA = headA;
    pB = headB;

    int diff = lenA - lenB;

    if (diff > 0) {
        for (int i = 0; i < diff; i++) {
            pA = pA->next;
        }
    } else {
        for (int i = 0; i < -diff; i++) {
            pB = pB->next;
        }
    }

    while (pA && pB) {
        if (pA == pB) {
            return pA;
        }
        pA = pA->next;
        pB = pB->next;
    }

    return NULL;
}

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = value;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* list1 = newNode(4);
    list1->next = newNode(1);

    struct Node* list2 = newNode(5);
    list2->next = newNode(6);
    list2->next->next = newNode(1);

    struct Node* common = newNode(8);
    common->next = newNode(4);
    common->next->next = newNode(5);

    list1->next->next = common;
    list2->next->next->next = common;

    struct Node* result = findIntersection(list1, list2);

    if (result) {
        printf("Intersection found at node with value: %d\n", result->val);
    } else {
        printf("No intersection found.\n");
    }

    return 0;
}