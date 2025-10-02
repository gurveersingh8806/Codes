#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int largestRectangle(int arr[], int n) {
    int stack[MAX];  
    int top = -1;    
    int maxArea = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || arr[i] >= arr[stack[top]]) {
            stack[++top] = i;
            i++;
        }
        else {
            int height = arr[stack[top--]];
            int width;

            if (top == -1) {
                width = i;  
            } else {
                width = i - stack[top] - 1;
            }

            int area = height * width;
            maxArea = max(maxArea, area);
        }
    }

    while (top != -1) {
        int height = arr[stack[top--]];
        int width;

        if (top == -1) {
            width = i;
        } else {
            width = i - stack[top] - 1;
        }

        int area = height * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Largest Rectangle Area = %d\n", largestRectangle(arr, n));
    return 0;
}
