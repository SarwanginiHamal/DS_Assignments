#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    DisjointSet ds(V);
    vector<Edge> mst;
    int totalWeight = 0;

    for (auto e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            ds.unite(e.u, e.v);
            mst.push_back(e);
            totalWeight += e.weight;
        }
    }
    cout << "Edges in MST (Kruskal's):\n";
    for (auto e : mst)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    cout << "Total weight = " << totalWeight << endl;
}
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    kruskalMST(V, edges);
    return 0;
}
