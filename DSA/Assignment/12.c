#include <stdio.h>

int findMaxProduct(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    int max_p = arr[0];
    int min_p = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        int current_val = arr[i];
        
        int temp_max = max_p;

        int choice1 = current_val;
        int choice2 = current_val * temp_max;
        int choice3 = current_val * min_p;

        if (choice1 > choice2) {
            max_p = choice1;
        } else {
            max_p = choice2;
        }
        if (choice3 > max_p) {
            max_p = choice3;
        }
        
        if (choice1 < choice2) {
            min_p = choice1;
        } else {
            min_p = choice2;
        }
        if (choice3 < min_p) {
            min_p = choice3;
        }

        if (max_p > result) {
            result = max_p;
        }
    }

    return result;
}

void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int nums1[] = {2, 3, -2, 4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printArray(nums1, n1);
    printf("Max product: %d\n\n", findMaxProduct(nums1, n1)); // Expected: 6 (from [2, 3])

    int nums2[] = {-2, 0, -1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printArray(nums2, n2);
    printf("Max product: %d\n\n", findMaxProduct(nums2, n2)); // Expected: 0

    int nums3[] = {-3, -1, -2, -4};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    printArray(nums3, n3);
    printf("Max product: %d\n\n", findMaxProduct(nums3, n3)); // Expected: 8 (from [-2, -4])

    return 0;
}