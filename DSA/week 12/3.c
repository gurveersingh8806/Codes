#include <stdio.h>

int main() {
    int n = 4;

    int trust[][2] = {
        {1, 3},
        {2, 3},
        {4, 3}
    };

    int m = sizeof(trust) / sizeof(trust[0]);

    int score[5];
    for (int i = 1; i <= n; i++) 
        score[i] = 0;

    for (int i = 0; i < m; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        score[a]--;
        score[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (score[i] == n - 1) {
            printf("Judge = %d", i);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
