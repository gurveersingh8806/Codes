#include <stdio.h>
#include <stdlib.h>

#define MAX 26 

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int popMax(int arr[], int *n) {
    if (*n == 0)
        return 0;
    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return max;
}

void pushHeap(int arr[], int *n, int val) {
    arr[*n] = val;
    (*n)++;
    int i = *n - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int leastInterval(char tasks[], int size, int n) {
    int freq[MAX] = {0};
    for (int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int heap[MAX];
    int heapSize = 0;

    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0)
            heap[heapSize++] = freq[i];
    }

    buildHeap(heap, heapSize);

    int time = 0;

    while (heapSize > 0) {
        int temp[100];
        int tempSize = 0;

        int cycle = n + 1;

        for (int i = 0; i < cycle; i++) {
            if (heapSize > 0) {
                int maxFreq = popMax(heap, &heapSize);
                if (maxFreq - 1 > 0)
                    temp[tempSize++] = maxFreq - 1;
            }
            time++;

            if (heapSize == 0 && tempSize == 0)
                break;
        }

        for (int i = 0; i < tempSize; i++)
            pushHeap(heap, &heapSize, temp[i]);
    }

    return time;
}

int main() {
    
    char tasks3[] = {'A','A','A','B','B','B'};
    int n3 = 3;
    printf("Output: %d\n", leastInterval(tasks3, 6, n3)); 

    return 0;
}
