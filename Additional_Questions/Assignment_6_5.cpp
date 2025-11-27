#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int x) : data(x), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

Node* constructDLLFrom2D(const vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return nullptr;
    int n = mat.size(), m = mat[0].size();
    vector<vector<Node*>> nodes(n, vector<Node*>(m, nullptr));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            nodes[i][j] = new Node(mat[i][j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j + 1 < m) {
                nodes[i][j]->next = nodes[i][j + 1];
                nodes[i][j + 1]->prev = nodes[i][j];
            }
            if (i + 1 < n) {
                nodes[i][j]->down = nodes[i + 1][j];
                nodes[i + 1][j]->up = nodes[i][j];
            }
        }
    }
    return nodes[0][0];
}

void printGrid(Node* head, int n, int m) {
    Node* row = head;
    for (int i = 0; i < n; ++i) {
        Node* col = row;
        for (int j = 0; j < m; ++j) {
            cout << col->data;
            if (j + 1 < m) cout << " <-> ";
            col = col->next;
        }
        cout << "\n";
        row = row->down;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Node* head = constructDLLFrom2D(mat);
    printGrid(head, 3, 3);

    return 0;
}
