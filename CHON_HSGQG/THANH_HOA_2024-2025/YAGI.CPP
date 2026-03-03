// https://codeforces.com/group/6iRxenZ3op/contest/675743/problem/C
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
int n, st, fn, m, dist[N];
struct Edges {
    int v, h, t;
};
vector<Edges> adj[N];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("YAGI.INP", "r", stdin);
    freopen("YAGI.OUT", "w", stdout);

    cin >> n >> st >> fn >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, h, t;
        cin >> u >> v >> h >> t;
        adj[u].push_back({v, h, t});
        adj[v].push_back({u, h, t});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dist, dist + N, 1e18);
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (Edges x : adj[u]) {
            if (dist[x.v] > max(d, x.h)) {
                dist[x.v] = max(d, x.h);
                pq.push({dist[x.v], x.v});
            }
        }
    }

    int bestH = dist[fn];

    fill(dist, dist + N, 1e18);
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        int t = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (t > dist[u]) continue;
        for (Edges x : adj[u]) {
            if (x.h > bestH) continue;
            if (dist[x.v] > t + x.t) {
                dist[x.v] = t + x.t;
                pq.push({dist[x.v], x.v});
            }
        }
    }

    cout << bestH << '\n' << dist[fn];

    return 0;
}
