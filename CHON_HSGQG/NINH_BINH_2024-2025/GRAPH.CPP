// https://codeforces.com/group/6iRxenZ3op/contest/676495/problem/C
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
const int LOG = 20;
int n, cnt[N], d[N];
vector<int> adj[N];
int p[N][LOG + 5], h[N];

void dfs(int u, int parent) {
    for (int v: adj[u]) {
        if (v == parent) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int get(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = LOG; i >= 0; --i) {
        if (h[p[u][i]] >= h[v]) {
            u = p[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG; i >= 0; --i) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

void dfs2(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs2(v, u);
        cnt[u] += cnt[v];
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);
    h[0] = -1;
    for (int j = 1; j <= LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        cnt[get(u, v)] -= 2;
    }
    dfs2(1, 1);
    int ans = 0;
    for (int i = 2; i <= n; ++i) if (cnt[i] == 0) ans++;
    cout << ans;
    return 0;
}
