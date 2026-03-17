#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
const int N = 5005;

vector<int> g[N], adj[N];
int par[N], h[N], p[N][LOG + 5];

int Find(int v) {
    return (v == par[v] ? v : par[v] = Find(par[v]));
}

void dfs(int u) {
    for (int v : adj[u]) {
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRIP.INP", "r", stdin);
    freopen("TRIP.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    iota(par, par + N, 0);
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            if (v > u) continue;
            int root_v = Find(v);
            if (root_v == u) continue;
            par[root_v] = u;
            adj[u].push_back(root_v);
//            cout << u << ' ' << root_v << '\n';
        }
    }

    h[0] = -1;
    for (int i = 1; i <= n; ++i) if (par[i] == i) dfs(i);

    for (int j = 1; j <= LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        if (s > t) {
            cout << -1 << '\n';
            continue;
        }
        if (s == t) {
            cout << 1 << '\n';
            continue;
        }

        int tmp = s;
        for (int i = LOG; i >= 0; --i) {
            if (h[p[s][i]] >= h[t]) s = p[s][i];
        }

        if (s == t) cout << h[tmp] - h[t] + 1 << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
