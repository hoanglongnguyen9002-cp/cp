#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
const int LOG = 20;
const int INF = INT_MAX;
int n;
int sz[N], par[N];
int h[N], p[N][LOG + 1], min_w[N][LOG + 1];

struct Edges {
    int u, v, w;
    bool operator < (const Edges &other) const {
        return w > other.w;
    }
};
vector<Edges> edges, upd;
vector<pair<int,int>> adj[N];

struct DSU {
    DSU() {
        fill(sz, sz + N, 1);
        iota(par, par + N, 0);
    }

    int Find(int v) {
        return (v == par[v] ? v : par[v] = Find(par[v]));
    }

    bool Union(int a, int b, int w) {
        int u = a, v = b;
        a = Find(a);
        b = Find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        return true;
    }
};

struct LCA {
    void dfs(int u, int parent) {
        for (pair<int,int> tmp : adj[u]) {
            int v = tmp.first;
            int w = tmp.second;
            if (v == parent) continue;
            h[v] = h[u] + 1;
            p[v][0] = u;
            min_w[v][0] = w;
            dfs(v, u);
        }
    }

    LCA() {
        for (int j = 1; j <= LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                min_w[i][j] = INF;
            }
        }
        dfs(1, 1);
        for (int j = 1; j <= LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                p[i][j] = p[p[i][j - 1]][j - 1];
                min_w[i][j] = min(min_w[i][j - 1], min_w[p[i][j - 1]][j - 1]);
            }
        }
        h[0] = -1;
    }

    int get(int u, int v) {
        if (h[u] < h[v]) swap(u, v);
        int res = INF;
        for (int i = LOG; i >= 0; --i) {
            if (h[p[u][i]] >= h[v]) {
                res = min(res, min_w[u][i]);
                u = p[u][i];
            }
        }
        if (u == v) return res;
        for (int i = LOG; i >= 0; --i) {
            if (p[u][i] != p[v][i]) {
                res = min({res, min_w[u][i], min_w[v][i]});
                u = p[u][i];
                v = p[v][i];
            }
        }
        res = min({res, min_w[u][0], min_w[v][0]});
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());
    DSU dsu;
    for (Edges tmp : edges) {
        int u = tmp.u;
        int v = tmp.v;
        int w = tmp.w;
        if (!dsu.Union(u, v, w)) upd.push_back({u, v, w});
    }
    LCA lca;
    ll ans = 0;
    for (Edges tmp : upd) {
        int u = tmp.u;
        int v = tmp.v;
        int w = tmp.w;
        ans += lca.get(u, v) - w;
    }
    cout << ans;
    return 0;
}

