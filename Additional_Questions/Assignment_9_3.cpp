#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(int N, vector<vector<int>>& times, int K) {
    const int INF = 1e9;
    vector<vector<pair<int,int>>> adj(N + 1);
    for (auto &e : times)
        adj[e[0]].push_back({e[1], e[2]});

    vector<int> dist(N + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == INF) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int main() {
    int N, E, K;
    cin >> N >> E >> K;
    vector<vector<int>> times(E, vector<int>(3));
    for (int i = 0; i < E; ++i)
        cin >> times[i][0] >> times[i][1] >> times[i][2];

    cout << networkDelayTime(N, times, K) << "\n";
    return 0;
}
