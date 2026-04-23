#include <bits/stdc++.h>
using namespace std;

bool isValid(int u, int v,
             vector<vector<int>>& graph,
             set<pair<int,int>>& forbidden) {

    if (graph[u][v] == 0) return false;
    if (forbidden.count({u, v}) || forbidden.count({v, u}))
        return false;
    return true;
}

bool solve(int pos, int n, vector<int>& path,
           vector<bool>& vis,
           vector<vector<int>>& graph,
           set<pair<int,int>>& forbidden,
           set<pair<int,int>>& mandatory) {

    if (pos == n) {
        if (!isValid(path[n-1], path[0], graph, forbidden))
            return false;

        for (auto &e : mandatory) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                int u = path[i];
                int v = path[(i+1)%n];
                if ((u == e.first && v == e.second) ||
                    (u == e.second && v == e.first)) {
                    found = true;
                }
            }
            if (!found) return false;
        }
        return true;
    }

    for (int v = 0; v < n; v++) {
        if (!vis[v] && isValid(path[pos-1], v, graph, forbidden)) {
            vis[v] = true;
            path[pos] = v;

            if (solve(pos+1, n, path, vis, graph, forbidden, mandatory))
                return true;

            vis[v] = false;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int f;
    cin >> f;
    set<pair<int,int>> forbidden;

    for (int i = 0; i < f; i++) {
        int u, v;
        cin >> u >> v;
        forbidden.insert({u, v});
    }

    int m;
    cin >> m;
    set<pair<int,int>> mandatory;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mandatory.insert({u, v});
    }

    int start;
    cin >> start;

    vector<int> path(n);
    vector<bool> vis(n, false);

    path[0] = start;
    vis[start] = true;

    if (solve(1, n, path, vis, graph, forbidden, mandatory)) {
        for (int i : path) cout << i << " ";
        cout << start;
    } else {
        cout << "No Hamiltonian Cycle";
    }
}