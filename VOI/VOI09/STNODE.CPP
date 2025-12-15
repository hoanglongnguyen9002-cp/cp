#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 1e4 + 4;
int n, m, s, t;
vector<int> adj[N];
int cand[N], dist[N], par[N];
bool vs[N];

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dist, dist + 1 + n, INF);
    pq.emplace(0, s);
    dist[s] = 0;
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + cand[v]) {
                dist[v] = dist[u] + cand[v];
                par[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    fill(cand, cand + 1 + n, 1);
    cand[s] = cand[t] = 0;
    while (true) {
        dijkstra();
        fill(vs, vs + 1 + n, false);
        int x = t;
        while (x != s) {
            vs[x] = true;
            x = par[x];
        }
        int check = false;
        for (int i = 1; i <= n; ++i) {
            if (cand[i] && !vs[i]) {
                cand[i] = 0;
                check = true;
            }
        }
        if (!check) break;
    }
    cout << accumulate(cand + 1, cand + 1 + n, 0);
    return 0;
}

