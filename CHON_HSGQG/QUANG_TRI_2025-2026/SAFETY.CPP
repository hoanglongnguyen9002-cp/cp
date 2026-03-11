#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
const int N = 2e5 + 5;

int n, m, q;
struct Edges {
    int u, v, w;
    bool operator < (const Edges &other) const {
        return w < other.w;
    }
};
vector<Edges> edges;
int sz[N], par[N];
int ans[N];
struct Node {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
} node[N];

int Find(int v) {
    return (v == par[v] ? v : par[v] = Find(par[v]));
}

void Union(int a, int b, int w) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;

    if (node[a].pq.size() < node[b].pq.size()) swap(node[a], node[b]);
    while (!node[b].pq.empty()) {
        node[a].pq.push(node[b].pq.top());
        node[b].pq.pop();
    }
    while (!node[a].pq.empty() && node[a].pq.top().first < sz[a]) {
        ans[node[a].pq.top().second] = w;
        node[a].pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    freopen("SAFETY.INP", "r", stdin);
//    freopen("SAFETY.OUT", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    fill(sz, sz + N, 1);
    iota(par, par + N, 0);
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= q; ++i) {
        int x, k;
        cin >> x >> k;
        node[x].pq.push({k, i});
    }

    for (Edges e : edges) Union(e.u, e.v, e.w);

    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';

    return 0;
}
