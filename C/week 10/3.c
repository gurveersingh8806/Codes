#include<stdio.h>

int main() {

    printf("Enter n:\n");
    int n;
    scanf("%d", &n);
    
    int A[n];
    int D[n]; 
    printf("Enter the values of array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        D[i] = 0; 
    }

    printf("The duplicate numbers are:\n");

    for (int j = 0; j < n; j++) {
        if (D[j])
        continue; 

        for (int k = j + 1; k < n; k++) {
            if (A[j] == A[k]) {
                if (!D[j]) {
                    printf("%d\n", A[j]);
                    D[j] = 1; 
                }
                D[k] = 1; 
            }
        }
    }

    return 0;
}