#include <stdio.h>

int main() {
    int adj[4][4] = {
        {0,1,1,0},  
        {1,0,0,1}, 
        {1,0,0,0},  
        {0,1,0,0}   
    };

    int visited[4] = {0};
    int queue[4];
    int front = 0, back = 0;

    int start = 0;  

    visited[start] = 1;
    queue[back++] = start;

    printf("BFS order: ");

    while (front < back) {
        int v = queue[front++];  
        printf("%d ", v + 1);

        for (int u = 0; u < 4; u++) {
            if (adj[v][u] == 1 && !visited[u]) {
                visited[u] = 1;
                queue[back++] = u;
            }
        }
    }

    return 0;
}
