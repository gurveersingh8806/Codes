#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void kthSmallest(struct Node* root, int k, int *count, int *result) {
    if (root == NULL)
        return;

    kthSmallest(root->left, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    kthSmallest(root->right, k, count, result);
}

void kthLargest(struct Node* root, int k, int *count, int *result) {
    if (root == NULL)
        return;

    kthLargest(root->right, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    kthLargest(root->left, k, count, result);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root,10);

    int k = 3;
    int count = 0, small = -1, large = -1;

    kthSmallest(root, k, &count, &small);

    count = 0;
    kthLargest(root, k, &count, &large);

    printf("%dth Smallest element = %d\n", k, small);
    printf("%dth Largest element = %d\n", k, large);

    return 0;
}