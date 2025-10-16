#include <stdio.h>

void sortTheArray(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int low = 0;
    int mid = 0;
    int high = size - 1;
    int temp;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                break;
            
            case 1:
                mid++;
                break;

            case 2:
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int my_nums[] = {0, 1, 2, 1, 2, 0, 1, 1, 0, 2, 1, 0};
    int n = sizeof(my_nums) / sizeof(my_nums[0]);

    printf("Original array: ");
    printArray(my_nums, n);

    sortTheArray(my_nums, n);

    printf("Sorted array:   ");
    printArray(my_nums, n);

    return 0;
}