#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
vector<int> adj[N];
int used[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            for (int j = i + 1; j < (int)adj[u].size(); ++j) {
                int x = adj[u][i];
                int y = adj[u][j];
                if (used[x][y]) {
                    cout << used[x][y] << ' ' << x << ' ' << u << ' ' << y;
                    return 0;
                }
                used[x][y] = u;
            }
        }
    }
    cout << -1;
    return 0;
}

