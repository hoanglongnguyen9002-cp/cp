#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m, k;
vector<int> adj[200001];
ll ra[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pair<ll,int>> pq;
    fill(ra, ra + 200001, -1);
    for (int i = 1; i <= k; ++i) {
        int p;
        ll r;
        cin >> p >> r;
        ra[p] = max(ra[p], r);
        pq.emplace(r, p);
    }
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d < ra[u]) continue;
        if (d == 0) continue;
        for (int v : adj[u]) {
            if (ra[v] < ra[u] - 1) {
                ra[v] = ra[u] - 1;
                pq.emplace(ra[u] - 1, v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << (ra[i] >= 0 ? 1 : 0);
    return 0;
}