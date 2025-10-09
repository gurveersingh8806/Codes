#include <stdio.h>
#include <stdlib.h>

int findMax(int *queue, int size) {
    int maxVal = queue[0];
    for (int i = 1; i < size; i++) {
        if (queue[i] > maxVal)
            maxVal = queue[i];
    }
    return maxVal;
}

int* Window(int* nums, int n, int k, int* Size) {
    int* ans = (int*)malloc((n - k + 1) * sizeof(int));

    int* window = (int*)malloc(k * sizeof(int));
    int front = 0, rear = 0; 

    for (int i = 0; i < k; i++) {
        window[rear++] = nums[i];
    }
    ans[0] = findMax(window, k);
    int idx = 1;

    for (int i = k; i < n; i++) {
        for (int j = 1; j < k; j++) {
            window[j - 1] = window[j];
        }
        rear = k - 1;
        window[rear] = nums[i];
        ans[idx++] = findMax(window, k);
    }

    free(window);
    *Size = n - k + 1;
    return ans;
}

int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    int Size;

    int* result = Window(nums, n, k, &Size);

    printf("Sliding window max: ");
    for (int i = 0; i < Size; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}
