#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> adj(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (i != j && adj[i][j] == -1) adj[i][j] = INF;
        }
    }

    vector<vector<vector<long long>>> dist(n,
        vector<vector<long long>>(n, vector<long long>(2, INF)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j][0] = 0;
                dist[i][j][1] = 0;
            } else if (adj[i][j] != INF) {
                dist[i][j][0] = adj[i][j];
                dist[i][j][1] = 0; 
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                dist[i][j][0] = min(dist[i][j][0],
                                    dist[i][k][0] + dist[k][j][0]);

                dist[i][j][1] = min({
                    dist[i][j][1],
                    dist[i][k][1] + dist[k][j][0],
                    dist[i][k][0] + dist[k][j][1] 
                });
            }
        }
    }

    cout << "Final shortest distances:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long ans = min(dist[i][j][0], dist[i][j][1]);
            if (ans >= INF) cout << "INF ";
            else cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}