#include <bits/stdc++.h>
using namespace std;

int dijkstraGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    const int INF = 1e9;
    vector<vector<int>> dist(m, vector<int>(n, INF));
    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], {0,0}});

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int d = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;
        if (d != dist[x][y]) continue;
        if (x == m-1 && y == n-1) return d;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            int nd = d + grid[nx][ny];
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({nd, {nx, ny}});
            }
        }
    }
    return dist[m-1][n-1];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    cout << dijkstraGrid(grid) << "\n";
    return 0;
}
