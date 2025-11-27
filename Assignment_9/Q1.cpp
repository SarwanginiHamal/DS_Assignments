#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adjList;
public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal starting from node " << start << ": ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};
int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    Graph g(vertices);
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v) format (0-based indexing):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int startNode;
    cout << "Enter starting node for BFS: ";
    cin >> startNode;
    g.BFS(startNode);
    return 0;
}
