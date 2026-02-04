#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, L, R, C, st, en;
    cin >> n >> L >> R >> C >> st >> en;
    vector<int> c(n + 1);
    map<int,vector<int>> adj;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        adj[c[i]].push_back(i);
    }
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    vector<long long> dist(n + 1, LLONG_MAX);
    pq.emplace(0, st);
    dist[st] = 0;
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d < dist[u]) continue;
        if (u + 1 <= n && dist[u + 1] > dist[u] + R) {
            dist[u + 1] = dist[u] + R;
            pq.emplace(dist[u + 1], u + 1);
        }
        if (u - 1 >= 1 && dist[u - 1] > dist[u] + L) {
            dist[u - 1] = dist[u] + L;
            pq.emplace(dist[u - 1], u - 1);
        }
        for (int v : adj[c[u]]) {
            if (dist[v] > dist[u] + C) {
                dist[v] = dist[u] + C;
                pq.emplace(dist[v], v);
            }
        }
    }
    cout << dist[en];
    return 0;
}
