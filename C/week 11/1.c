#include <stdio.h>
#include <stdlib.h>

void findIntersection(int A[], int B[], int n, int m) {
    printf("A ∩ B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                int found = 0;
                for (int k = 0; k < i; k++) {
                    if (A[k] == A[i]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("%d ", A[i]);
                }
            }
        }
    }
    printf("\n");
}

void findUnion(int A[], int B[], int n, int m) {
    printf("A U B:\n");
    int C[n + m], k = 0;

    for (int i = 0; i < n; i++) 
    C[k++] = A[i];
    for (int i = 0; i < m; i++) 
    C[k++] = B[i];

    for (int i = 0; i < k; i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (C[i] == C[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("%d ", C[i]);
    }
    printf("\n");
}

void findDifference(int A[], int B[], int n, int m) {
    printf("A - B:\n");
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d ", A[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, m;

    printf("Enter n:\n");
    scanf("%d", &n);
    int A[n];

    printf("Enter array 1 elements:\n");
    for (int i = 0; i < n; i++)
    scanf("%d", &A[i]);

    printf("Enter m:\n");
    scanf("%d", &m);
    int B[m];

    printf("Enter array 2 elements:\n");
    for (int i = 0; i < m; i++) 
    scanf("%d", &B[i]);

    int c;
    while (1) {
        printf("\nWhat do you want to find?\n1. A n B\n2. A u B\n3. A - B\n4. Exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1: findIntersection(A, B, n, m); 
                    break;
            case 2: findUnion(A, B, n, m);
                    break;
            case 3: findDifference(A, B, n, m); 
                    break;
            case 4: printf("End of code.\n"); 
                    exit(0);
        }
    }

    return 0;
}