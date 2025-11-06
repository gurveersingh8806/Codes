#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] > heap[largest])
        largest = l;
    if (r < n && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void pushHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    int i = *n - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int popHeap(int heap[], int *n) {
    if (*n == 0)
        return 0;
    int max = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return max;
}

int minRefuelStops(int target, int startFuel, int stations[][2], int n) {
    int i = 0, stops = 0, heap[1000], heapSize = 0;
    int fuel = startFuel;

    while (fuel < target) {
        while (i < n && stations[i][0] <= fuel) {
            pushHeap(heap, &heapSize, stations[i][1]);
            i++;
        }

        if (heapSize == 0)
            return -1;

        fuel += popHeap(heap, &heapSize);
        stops++;
    }

    return stops;
}

int main() {

    int stations3[4][2] = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    printf("Output: %d\n", minRefuelStops(100, 10, stations3, 4)); 

    return 0;
}
