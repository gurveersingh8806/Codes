#include <stdio.h>

int main() {
    int n = 4;

    int graph[][3] = {
        {2, 1, 3},
        {1, 2, -1},
        {0, -1, -1},
        {1, 2, -1}
    };

    int visited[4] = {0};
    int stack[10], top = -1;

    stack[++top] = 0;
    visited[0] = 1;

    while (top != -1) {
        int r = stack[top--];
        int k = graph[r][0];
        for (int i = 1; i <= k; i++) {
            int v = graph[r][i];
            if (!visited[v]) {
                visited[v] = 1;
                stack[++top] = v;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("false");
            return 0;
        }
    }

    printf("true");
    return 0;
}
