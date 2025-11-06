#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* root, int arr[], int *n) {
    if (root == NULL) return;
    inorder(root->left, arr, n);
    arr[(*n)++] = root->data;
    inorder(root->right, arr, n);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int t = arr[0]; arr[0] = arr[i]; arr[i] = t;
        heapify(arr, i, 0);
    }
}

void kthSmallLarge(struct Node* root, int k) {
    int arr[100], n = 0;
    inorder(root, arr, &n);
    heapSort(arr, n);

    if (k <= 0 || k > n) {
        printf("Invalid k\n");
        return;
    }

    printf("Kth Smallest = %d\n", arr[k-1]);
    printf("Kth Largest = %d\n", arr[n-k]);
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(10);

    int k = 2;
    kthSmallLarge(root, k);

    return 0;
}
