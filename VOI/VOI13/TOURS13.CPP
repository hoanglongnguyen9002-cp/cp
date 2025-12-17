#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
vector<pair<int,int>> adj[N];
int dist[N];

int dijkstra(int s) {
    fill(dist, dist + N, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (pair<int,int> tmp : adj[s]) {
        int v = tmp.first;
        int w = tmp.second;
        dist[v] = w;
        pq.emplace(dist[v], v);
    }
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (u == s) return d;
        if (d > dist[u]) continue;
        for (pair<int,int> tmp : adj[u]) {
            int v = tmp.first;
            int w = tmp.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return -1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    for (int i = 1; i <= n; ++i) cout << dijkstra(i) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}

