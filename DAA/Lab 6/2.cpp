#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

struct Edge {
    int to, weight;
};

int main() {
    int N, M, K;
    cout << "Enter nodes, edges: ";
    cin >> N >> M;

    vector<vector<Edge>> graph(N);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }

    cout << "Enter source: ";
    int S;
    cin >> S;

    cout << "Enter K violations: ";
    cin >> K;

    vector<vector<int>> dist(N, vector<int>(K + 1, INF));

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

    dist[S][0] = 0;
    pq.push({0, S, 0});

    while (!pq.empty()) {
        auto [d, node, used] = pq.top();
        pq.pop();

        if (d > dist[node][used]) continue;

        for (auto e : graph[node]) {
            int next = e.to;
            int newDist = d + e.weight;

            if (newDist < dist[next][used]) {
                dist[next][used] = newDist;
                pq.push({newDist, next, used});
            }

            if (used < K && d < dist[next][used + 1]) {
                dist[next][used + 1] = d;
                pq.push({d, next, used + 1});
            }
        }
    }

    cout << "Shortest distances:\n";
    for (int i = 0; i < N; i++) {
        int ans = *min_element(dist[i].begin(), dist[i].end());
        cout << "Node " << i << " -> " << ans << endl;
    }

    return 0;
}
