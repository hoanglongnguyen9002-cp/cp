// https://codeforces.com/group/6iRxenZ3op/contest/676722/problem/C
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
const int INF = 1e8;
const int LOG = 20;
int n, q, ans[N];
int h[N], p[N][LOG + 5], mn[N][LOG + 5];
int sz[N], par[N];
bool del[N];
vector<pair<int,int>> adj[N];

struct Query {
    int idx, type, u, v, ans;
};
vector<Query> query;

void dfs(int u, int parent) {
    for (pair<int,int> e : adj[u]) {
        int v = e.first;
        int w = e.second;
        if (v == parent) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        mn[v][0] = w;
        dfs(v, u);
    }
}

int get(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int res = INF;
    for (int i = LOG; i >= 0; --i) {
        if (h[p[u][i]] >= h[v]) {
            res = min(res, mn[u][i]);
            u = p[u][i];
        }
    }
    if (u == v) return res;
    for (int i = LOG; i >= 0; --i) {
        if (p[u][i] != p[v][i]) {
            res = min({res, mn[u][i], mn[v][i]});
            u = p[u][i];
            v = p[v][i];
        }
    }
    res = min({res, mn[u][0], mn[v][0]});
    return res;
}

int Find(int v) {
    return (v == par[v] ? v : par[v] = Find(par[v]));
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    freopen("BITLAND.INP", "r", stdin);
//    freopen("BITLAND.OUT", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= LOG; ++j) {
            mn[i][j] = INF;
        }
    }

    dfs(1, 1);

    h[0] = -1;
    for (int j = 1; j <= LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
            mn[i][j] = min(mn[i][j - 1], mn[p[i][j - 1]][j - 1]);
        }
    }

    for (int i = 0; i < q; ++i) {
        int type, u;
        cin >> type >> u;
        if (type == 1) {
            int v;
            cin >> v;
            int x = get(u, v);
            query.push_back({i, type, u, v, x});
        } else {
            del[u] = true;
            query.push_back({i, type, u, -1, -1});
        }
    }

    iota(par, par + N, 0);
    fill(sz, sz + N, 1);

    for (int u = 1; u <= n; ++u) {
        if (del[u]) continue;
        for (pair<int,int> e : adj[u]) {
            if (del[e.first]) continue;
            Union(u, e.first);
        }
    }

    for (int i = q - 1; i >= 0; --i) {
        int type = query[i].type;
        int u = query[i].u;
        if (type == 1) {
            int v = query[i].v;
//            cout << type << ' ' << u << ' ' << v << endl;
            u = Find(u);
            v = Find(v);
            if (u != v) ans[query[i].idx] = -1;
            else ans[query[i].idx] = (query[i].ans == INF ? 0 : query[i].ans);
        } else {
            del[u] = false;
            for (auto e : adj[u]) {
                if (!del[e.first]) Union(u, e.first);
            }
        }

    }

    for (int i = 0; i < q; ++i) if (query[i].type == 1) cout << ans[i] << '\n';

    return 0;
}
