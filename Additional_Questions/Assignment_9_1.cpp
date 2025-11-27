#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs(v, adj, vis);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);
    int components = 0;
    for (int i = 0; i < V; ++i)
        if (!vis[i]) {
            components++;
            dfs(i, adj, vis);
        }

    cout << components << "\n";
    return 0;
}
