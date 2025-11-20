#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int edges[n-1][2];
    for (int i = 0; i < n-1; i++)
        scanf("%d %d", &edges[i][0], &edges[i][1]);

    int a = edges[0][0], b = edges[0][1];
    int x = edges[1][0], y = edges[1][1];

    if (a == x || a == y) printf("%d", a);
    else printf("%d", b);

    return 0;
}
