#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* add(Node* head, int v) {
    Node* n = malloc(sizeof(Node));
    n->v = v;
    n->next = head;
    return n;
}

int main() {
    int L, R, E;
    scanf("%d %d %d", &L, &R, &E);

    int V = L + R;
    Node* adj[V];
    for (int i = 0; i < V; i++) 
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        v += L;
        adj[u] = add(adj[u], v);
        adj[v] = add(adj[v], u);
    }

    for (int i = 0; i < V; i++) {
        printf("%d:", i);
        Node* p = adj[i];
        while (p) {
            printf(" %d", p->v);
            p = p->next;
        }
        printf("\n");
    }

    return 0;
}
