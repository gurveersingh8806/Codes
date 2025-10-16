#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int* fwd = (int*)malloc(n * sizeof(int));
    int* bwd = (int*)malloc(n * sizeof(int));

    int curr_max = arr[0];
    int total_max = arr[0];
    fwd[0] = arr[0];

    for (int i = 1; i < n; i++) {
        curr_max = max(arr[i], curr_max + arr[i]);
        total_max = max(total_max, curr_max);
        fwd[i] = curr_max;
    }

    curr_max = arr[n - 1];
    bwd[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        curr_max = max(arr[i], curr_max + arr[i]);
        bwd[i] = curr_max;
    }

    int final_max = total_max;

    for (int i = 1; i < n - 1; i++) {
        final_max = max(final_max, fwd[i - 1] + bwd[i + 1]);
    }

    free(fwd);
    free(bwd);

    return final_max;
}

int main() {
    int my_array[] = {1, -2, 0, 3};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    printf("Array: 1, -2, 0, 3\n");
    printf("Max sum is: %d\n\n", solve(my_array, size)); // Expected: 4 (1 + 3, deleting -2 and 0)

    int my_array2[] = {1, -2, -2, 3};
    int size2 = sizeof(my_array2) / sizeof(my_array2[0]);
    printf("Array: 1, -2, -2, 3\n");
    printf("Max sum is: %d\n\n", solve(my_array2, size2)); // Expected: 3 (just the element 3)

    int my_array3[] = {-2, -3, -1, -5, -4};
    int size3 = sizeof(my_array3) / sizeof(my_array3[0]);
    printf("Array: -2, -3, -1, -5, -4\n");
    printf("Max sum is: %d\n\n", solve(my_array3, size3)); // Expected: -1 (no deletion)
    
    return 0;
}