#include <stdio.h>
#include <math.h>

void findMissingNumbers(int arr[], int size, int i, int n) {
    int totalSum = 0, totalSquareSum = 0;
    int actualSum = 0, actualSquareSum = 0;
    
    for (int x = i; x <= n+2; x++) {
        totalSum += x;
        totalSquareSum += x * x;
    }
    
    for (int j = 0; j < size; j++) {
        actualSum += arr[j];

        
        actualSquareSum += arr[j] * arr[j];
    }
    
    int sumDiff = totalSum - actualSum;  
    int squareSumDiff = totalSquareSum - actualSquareSum;

    int xyProduct = (sumDiff * sumDiff - squareSumDiff) / 2;  


    int discriminant = sqrt(sumDiff * sumDiff - 4 * xyProduct);
    int x = (sumDiff + discriminant) / 2;
    int y = sumDiff - x;

    printf("Missing numbers: %d and %d\n", x, y);
}


int main() {
    int arr[] = {3, 4, 6, 7, 8, 9, 10}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int i = 3, n = 9;

    findMissingNumbers(arr, size, i, n);
    
    return 0;
}