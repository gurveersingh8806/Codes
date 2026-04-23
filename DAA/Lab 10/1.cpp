#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color, vector<int>& col, vector<vector<int>>& adj) {
    for (int nei : adj[node]) {
        if (col[nei] == color)
            return false;
    }
    return true;
}

bool solve(int node, int n, int k, vector<int>& col, vector<vector<int>>& adj) {
    if (node == n) return true;

    if (col[node] != 0)
        return solve(node + 1, n, k, col, adj);

    for (int c = 1; c <= k; c++) {
        if (isSafe(node, c, col, adj)) {
            col[node] = c;
            if (solve(node + 1, n, k, col, adj))
                return true;
            col[node] = 0;
        }
    }
    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> col(n, 0);

    int p; // pre-colored count
    cin >> p;

    for (int i = 0; i < p; i++) {
        int node, color;
        cin >> node >> color;
        col[node] = color;
    }

    if (solve(0, n, k, col, adj)) {
        for (int i = 0; i < n; i++)
            cout << col[i] << " ";
    } else {
        cout << "No solution";
    }
}