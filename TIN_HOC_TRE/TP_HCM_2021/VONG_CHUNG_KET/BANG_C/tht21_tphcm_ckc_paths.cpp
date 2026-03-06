// https://oj.vnoi.info/problem/tht21_tphcm_ckc_paths
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;
const int LOG = 20;
const int INF = 1e18;
int n, m, ans[N];
int par[N], sz[N];
int p[N][LOG + 1], mx[N][LOG + 1], h[N];
struct Edges {
    int idx, u, v, w;
    bool operator < (const Edges &other) const {
        return w < other.w;
    }
};
vector<Edges> edges;
vector<pair<int,int>> adj[N];

int Find(int v) {
    return (v == par[v] ? v : par[v] = Find(par[v]));
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

void dfs(int u, int parent) {
    for (pair<int,int> x : adj[u]) {
        int v = x.first;
        int w = x.second;
        if (v == parent) continue;
        p[v][0] = u;
        mx[v][0] = w;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int get(int u, int v) {
    int res = -INF;
    if (h[u] < h[v]) swap(u, v);
    for (int i = LOG; i >= 0; --i) {
        if (h[p[u][i]] >= h[v]) {
            res = max(res, mx[u][i]);
            u = p[u][i];
        }
    }
    if (u == v) return res;
    for (int i = LOG; i >= 0; --i) {
        if (p[u][i] != p[v][i]) {
            res = max({res, mx[u][i], mx[v][i]});
            u = p[u][i];
            v = p[v][i];
        }
    }
    res = max({res, mx[u][0], mx[v][0]});
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({i, u, v, w});
    }
    sort(edges.begin(), edges.end());

    fill(sz, sz + N, 1);
    iota(par, par + N, 0);
    int sum = 0;
    for (Edges x : edges) {
        if (Union(x.u, x.v)) {
            adj[x.u].push_back({x.v, x.w});
            adj[x.v].push_back({x.u, x.w});
            sum += x.w;
        }
    }
    dfs(1, 1);
    h[0] = -1;
    for (int j = 1; j <= LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[p[i][j - 1]][j - 1]);
        }
    }


    for (int i = 0; i < m; ++i) {
        ans[edges[i].idx] = sum - get(edges[i].u, edges[i].v) + edges[i].w;
    }

    for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';

    return 0;
}
