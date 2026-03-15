#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
vector<pair<int,int>> adj[N], radj[N];
vector<long long> dist(N, LLONG_MAX), rdist(N, LLONG_MAX);

void dijkstra(vector<pair<int,int>> g[], vector<long long> &d) {
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.emplace(0, 1);
    d[1] = 0;
    while(!pq.empty()) {
        long long f = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (f > d[u]) continue;
        for (pair<int,int> tmp : g[u]) {
            int v = tmp.first;
            int w = tmp.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        radj[v].emplace_back(u, w);
    }
    dijkstra(adj, dist);
    dijkstra(radj, rdist);
    for (int i = 2; i <= n; ++i) {
        if (dist[i] == LLONG_MAX || rdist[i] == LLONG_MAX) cout << -1 << '\n';
        else cout << dist[i] + rdist[i] << '\n';
    }
    return 0;
}
