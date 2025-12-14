#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
const int LOG = 20;
int n, w[N], k;
ll dp[N];
vector<int> adj[N];
int h[N], p[N][LOG + 1], max_w[N][LOG + 1];

struct LCA {
    void dfs(int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            h[v] = h[u] + 1;
            p[v][0] = u;
            max_w[v][0] = max(w[u], w[v]);
            dfs(v, u);
        }
    }

    LCA() {
        dfs(1, 1);
        for (int j = 1; j <= LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                p[i][j] = p[p[i][j - 1]][j - 1];
                max_w[i][j] = max(max_w[i][j - 1], max_w[p[i][j - 1]][j - 1]);
            }
        }
        h[0] = -1;
    }

    int get(int u, int v) {
        int res = INT_MIN;
        if (h[u] < h[v]) swap(u, v);
        for (int i = LOG; i >= 0; --i) {
            if (h[p[u][i]] >= h[v]) {
                res = max(res, max_w[u][i]);
                u = p[u][i];
            }
        }
        if (u == v) return res;
        for (int i = LOG; i >= 0; --i) {
            if (p[u][i] != p[v][i]) {
                res = max({res, max_w[u][i], max_w[v][i]});
                u = p[u][i];
                v = p[v][i];
            }
        }
        res = max({res, max_w[u][0], max_w[v][0]});
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SHIP.INP", "r", stdin);
    freopen("SHIP.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int u, v;
        cin >> u >> v;
        if (dp[u] == 0 && u != 1) continue;
        dp[v] = max(dp[v], dp[u] + lca.get(u, v));
    }
    cout << *max_element(dp + 1, dp + 1 + n);
    return 0;
}
