#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adjList;
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }
public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from node " << start << ": ";
        DFSUtil(start, visited);
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
    cout << "Enter starting node for DFS: ";
    cin >> startNode;
    g.DFS(startNode);
    return 0;
}
