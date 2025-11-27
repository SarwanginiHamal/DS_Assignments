#include <bits/stdc++.h>
using namespace std;

void dijkstra(int V, vector<vector<pair<int,int>>>& adj, int start) {
    vector<int> dist(V, INT_MAX); 
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << ": INF\n";
        else
            cout << i << ": " << dist[i] << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges (u v weight) format (0-based indexing):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    dijkstra(V, adj, start);
    return 0;
}
