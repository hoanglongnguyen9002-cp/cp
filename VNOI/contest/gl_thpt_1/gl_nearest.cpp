// https://oj.vnoi.info/problem/gl_nearest#submit
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m, b, r, food[N], army[N], dist[N];
vector<int> adj[N];

void bfs() {
    fill(dist, dist + N, 1e9);
    queue<int> q;
    for (int i = 1; i <= b; ++i) {
        q.push(food[i]);
        dist[food[i]] = 0;
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> b >> r;
    for (int i = 1; i <= b; ++i) cin >> food[i];
    for (int i = 1; i <= r; ++i) cin >> army[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();
    for (int i = 1; i <= r; ++i) cout << dist[army[i]] << ' ';
    
    return 0;
}
